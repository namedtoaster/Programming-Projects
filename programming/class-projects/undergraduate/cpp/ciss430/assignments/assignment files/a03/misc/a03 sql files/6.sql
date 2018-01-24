SELECT (vendor_contact_last_name || ', ' || vendor_contact_first_name) AS full_name
FROM vendors
WHERE vendor_contact_last_name LIKE 'A%'
OR WHERE vendor_contact_last_name LIKE 'B%'
OR WHERE vendor_contact_last_name LIKE 'C%'
OR WHERE vendor_contact_last_name LIKE 'E%'
ORDER BY full_name;