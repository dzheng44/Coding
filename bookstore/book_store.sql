-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: May 03, 2022 at 05:25 AM
-- Server version: 10.4.22-MariaDB
-- PHP Version: 7.4.27

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `book_store`
--

-- --------------------------------------------------------

--
-- Table structure for table `books`
--

CREATE TABLE `books` (
  `BookName` varchar(50) NOT NULL,
  `Author` varchar(35) NOT NULL,
  `Genre` varchar(35) NOT NULL,
  `ISBN` varchar(15) NOT NULL,
  `Price` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `books`
--

INSERT INTO `books` (`BookName`, `Author`, `Genre`, `ISBN`, `Price`) VALUES
('One Piece: Romance Dawn', 'Eiichiro Oda', 'Fiction', '9788925285641', 10.99),
('Frankenstein', 'Mary Shelley', 'Horror', '9780140432374', 10.99),
('Harry Potter and the Sorcerer\'s Stone', 'J.K. Rowling', 'Fantasy', '9780807286005', 10.99),
('The Book Thief', 'Markus Zusak', 'Historical Fiction', '9780552773898', 10.99),
('Magic Treehouse Dinosaurs Before Dark', 'Mary Pope Osborne', 'Fiction', '9780375894183', 10.99);

-- --------------------------------------------------------

--
-- Table structure for table `cart`
--

CREATE TABLE `cart` (
  `Username` varchar(35) NOT NULL,
  `ISBN` varchar(15) NOT NULL,
  `Stock` int(11) NOT NULL,
  `Price` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `cart_history`
--

CREATE TABLE `cart_history` (
  `cart_number` varchar(35) NOT NULL,
  `ISBN` varchar(35) NOT NULL,
  `quantity` int(35) NOT NULL,
  `total_price` double NOT NULL,
  `username` varchar(35) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `inventory`
--

CREATE TABLE `inventory` (
  `ISBN` varchar(35) NOT NULL,
  `Stock` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `inventory`
--

INSERT INTO `inventory` (`ISBN`, `Stock`) VALUES
('9788925285641', 6),
('9780140432374', 9),
('9780807286005', 10),
('9780552773898', 10),
('9780375894183', 10);

-- --------------------------------------------------------

--
-- Table structure for table `user_info`
--

CREATE TABLE `user_info` (
  `Name` varchar(35) NOT NULL,
  `Username` varchar(35) NOT NULL,
  `Password` varchar(35) NOT NULL,
  `Address` varchar(35) NOT NULL,
  `City` varchar(35) NOT NULL,
  `State` varchar(35) NOT NULL,
  `Zip Code` int(35) NOT NULL,
  `Payment Info` varchar(35) NOT NULL,
  `Shipping Info` varchar(35) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `user_info`
--

INSERT INTO `user_info` (`Name`, `Username`, `Password`, `Address`, `City`, `State`, `Zip Code`, `Payment Info`, `Shipping Info`) VALUES
('John Dow', 'JD', '123', '12 abc', 'Stark', 'MS', 39759, 'Card', '12 abc, Stark MS, 39759');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
