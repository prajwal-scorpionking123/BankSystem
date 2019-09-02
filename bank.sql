-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Sep 01, 2019 at 08:00 PM
-- Server version: 10.1.39-MariaDB
-- PHP Version: 7.3.5

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `bank`
--

-- --------------------------------------------------------

--
-- Table structure for table `accounts`
--

CREATE TABLE `accounts` (
  `ACCOUNT_NUMBER` int(11) NOT NULL,
  `FNAME` text NOT NULL,
  `MNAME` text NOT NULL,
  `LNAME` text NOT NULL,
  `GENDER` text NOT NULL,
  `TYPE` text NOT NULL,
  `MOB_NO` text NOT NULL,
  `AADHAR` text NOT NULL,
  `STATE` text NOT NULL,
  `CITY` text NOT NULL,
  `BALANCE` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `accounts`
--

INSERT INTO `accounts` (`ACCOUNT_NUMBER`, `FNAME`, `MNAME`, `LNAME`, `GENDER`, `TYPE`, `MOB_NO`, `AADHAR`, `STATE`, `CITY`, `BALANCE`) VALUES
(16, 'PRAJWAL', 'UPALI', 'PATIL', 'MALE', 'SAVINGS', '9657871360', '90876754311', 'MAHA', 'NAG', 12000),
(17, 'pinak', 'n', 'acharya', 'm', 'saving', '9774739879483', '7748570437', 'maha', 'nag', 130909);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `accounts`
--
ALTER TABLE `accounts`
  ADD PRIMARY KEY (`ACCOUNT_NUMBER`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `accounts`
--
ALTER TABLE `accounts`
  MODIFY `ACCOUNT_NUMBER` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=18;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
