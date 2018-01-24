SELECT account_description, COUNT(ili.account_number) AS "NUMBER OF ACCOUNTS", SUM(line_item_amt) AS "LINE ITEM AMT TOTAL"
FROM general_ledger_accounts gla JOIN invoice_line_items ili ON gla.account_number = ili.account_number
GROUP BY account_description
HAVING COUNT(ili.account_number) > 1
ORDER BY SUM(ili.line_item_amt) DESC;