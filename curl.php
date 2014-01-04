<?php

define(SEP_WORD,';');
define(SEP_RECORD,'#');

$in = $_POST['curl'];
$sid = $_POST['sid'];
$crc = $_POST['crc'];
if(isset($in) && isset($sid) && isset($crc))
{
	$md5_in = $in.$sid."Alamakotaakotmacostamwzebach759823728375";
	$md5 = md5($md5_in);
	
	if($md5!=$crc)
	{
		echo base64_encode('0');
		die();
	}
	
	$str_in = base64_decode(trim($in));
	$str_in = trim($str_in);
	$counter = substr_count($str_in,SEP_RECORD);
	
	if($counter>0 && $str_in!='GET') 
	{
		$show = '';
		$res = mysql_query("SELECT * FROM `neurocalc` ");
		$db_index = 0;
		while($row = mysql_fetch_array($res))
		{
			$words = explode(SEP_WORD,$row['var']);
			$db[$db_index] = $words;
			$db_ids[$db_index] = $row['id'];
			$db_index++;
		}
		$records = explode(SEP_RECORD,$str_in);
		for($jj=0;$jj<$counter;$jj++)
		{
			$words = explode(SEP_WORD,$records[$jj]);
			$found = false;
			for ($ii=0;$ii<count($db);$ii++)
			{
				if($words[0]==$db[$ii][0] && $words[1]==$db[$ii][1] && $words[2]==$db[$ii][2])
				{	
					// jesli data klienta jest nowsza od daty z serwera
					$time_client = str_replace('.','-',$words[12]);
					$time_srv = str_replace('.','-',$db[$ii][12]);
					if(strtotime($time_client)>strtotime($time_srv))
						$res = mysql_query("UPDATE `neurocalc` SET `var` = '".$records[$jj]."' WHERE `id` = ".$db_ids[$ii]);	
					$found = true;
					break;
				}			
			}
			if(!$found)
				$res = mysql_query("INSERT INTO `neurocalc` (`id`,`var`,`date`) VALUES (NULL, '".$records[$jj]."', NULL)");
		}
		echo base64_encode($counter); 
	}
	else if($counter==0 && $str_in!='GET')
	{
		echo base64_encode('0'); 
	}
	else if($str_in=='GET')
	{
		$show = '';
		$counter = 0;
		$res = mysql_query("SELECT * FROM `neurocalc` ");
		while($row = mysql_fetch_array($res))
		{
			$counter++;
			$show .= $row['var'].SEP_RECORD;
		}
		echo base64_encode($counter.SEP_RECORD.$show);
	}
	else echo base64_encode('0');
	die();
}
else 
{
	$res = mysql_query("SELECT * FROM `neurocalc` ");
	while($row = mysql_fetch_array($res))
		echo $row['id'].' | '.$row['var'].' | '.$row['date'].'<br />';
}
die();


?>