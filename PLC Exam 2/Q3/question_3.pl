#!/usr/bin/perl

#
# Testing out hashes
#

# test out size, access, add, remove, and slice

# With hash
%hashExample = (-January => 15, 
                -February => 16,
                -March => 15, 
                'April' => 15,
                -May => 15, 
                'June' => 15,
                'July' => 15, 
                'August' => 15,
                'September' => 15, 
                'October' => 15,
                'November' => 15, 
                'December' => 15,);
                

#get size
@keys = keys %hashExample;
$size = @keys;
print "Total months are $size\n";

#access
print "$hashExample{'Apples'}\n";
print "Give it up for day $hashExample{'January'} of January\n";
print "Give it up for day $hashExample{'April'} of April\n";

#add
$hashExample{'Grapes'} = 15;
$hashExample{'Pears'} = 15;
$hashExample{'Bananas'} = 15;

@keys = keys %hashExample;
$size = @keys;
print "New size after additions is $size\n";

#remove
delete $hashExample{'Grapes'};
@keys = keys %hashExample;
$size = @keys;
print "New size after deletion is $size\n";

#slice
@array = @hashExample{-January, -February, -March, -May};
print "Array : @array\n";

# Without hash, using parallel arrays

@hashNames = ('January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December');
@hashValues = (15, 16, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15);

#get size
$size = @hashNames;
print "Size of hash names is $size\n";

$size = @hashValues;
print "Size of hash values is $size\n";

#access
@indexGet = index ($hashNames, 'Apples');
print "$indexGet\n";

@indexGet = index ($hashNames, 'January');
@indexResult = $hashValues[$indexGet];
print "$indexGet $indexResult\n";

@indexGet = index ($hashNames, 'April');
@indexResult = $hashValues[$indexGet];
print "$indexGet $indexResult\n";

#add
push(@hashNames, 'Apples');
push(@hashValues, 15);

push(@hashNames, 'Oranges');
push(@hashValues, 14);

push(@hashNames, 'Grapes');
push(@hashValues, 15);

$size = @hashNames;
print "Size of hash names is $size\n";

$size = @hashValues;
print "Size of hash values is $size\n";

@indexGet = index ($hashNames, 'Oranges');
@indexResult = $hashValues[$indexGet];
print "$indexGet $indexResult\n";


#remove
pop(@hashNames);
pop(@hashValues);

$size = @hashNames;
print "Size of hash names is $size\n";

$size = @hashValues;
print "Size of hash values is $size\n";

@indexGet = index ($hashNames, 'Grapes');
print "Index of grapes is $indexGet\n";


#slice
@indexGet1 = index ($hashNames, 'January');
@indexGet2 = index ($hashNames, 'April');

@arraySlice = @hashValues[$indexGet1..$indexGet2];
print "@arraySlice\n";
