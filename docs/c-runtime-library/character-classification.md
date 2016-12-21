---
title: "Classifica&#231;&#227;o de caractere | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "c.types.character"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "rotinas de classificação de caracteres"
  - "caracteres, testando"
ms.assetid: 3b6c8f0b-9701-407a-b384-9086698773f5
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classifica&#231;&#227;o de caractere
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cada uma dessas rotinas testa um caractere especificado de byte único, caractere amplo, ou caractere de multibyte para satisfazer uma condição. \(Por definição, o conjunto de caracteres ASCII entre 0 e 127 é um subconjunto de todos os conjuntos de caracteres multibyte.  Por exemplo, o katakana japonês inclui caracteres ASCII bem como não\-ASCII.  
  
 As condições de teste são afetadas pela configuração da categoria `LC_CTYPE` de localidade. Para obter mais informações, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).  As versões dessas funções sem o sufixo `_l` usam a localidade atual para esse comportamento dependente da localidade; as versões com o sufixo `_l` são idênticas, exceto que elas usam o parâmetro de localidade informado.  
  
 Geralmente essas rotinas executam mais rápido do que os testes que você pode escrever e devem ser favorecidas.  Por exemplo, o código a seguir é executado mais lento do que uma chamada para `isalpha(c)`:  
  
```  
if ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z'))  
    return TRUE;  
```  
  
### Rotinas de classificação de caracteres  
  
|Rotina|Condição de teste de caracteres|Equivalente a .NET Framework|  
|------------|-------------------------------------|----------------------------------|  
|[isalnum, iswalnum, \_isalnum\_l, \_iswalnum\_l](../Topic/isalnum,%20iswalnum,%20_isalnum_l,%20_iswalnum_l.md), [\_ismbcalnum, \_ismbcalnum\_l, \_ismbcalpha, \_ismbcalpha\_l, \_ismbcdigit, \_ismbcdigit\_l](../Topic/_ismbcalnum,%20_ismbcalnum_l,%20_ismbcalpha,%20_ismbcalpha_l,%20_ismbcdigit,%20_ismbcdigit_l.md)|Alfanumérico|[System::Char::IsLetterOrDigit](https://msdn.microsoft.com/en-us/library/system.char.isletterordigit.aspx).|  
|[\_ismbcalnum, \_ismbcalnum\_l, \_ismbcalpha, \_ismbcalpha\_l, \_ismbcdigit, \_ismbcdigit\_l](../Topic/_ismbcalnum,%20_ismbcalnum_l,%20_ismbcalpha,%20_ismbcalpha_l,%20_ismbcdigit,%20_ismbcdigit_l.md)|Alfanumérico|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[isalpha, iswalpha, \_isalpha\_l, \_iswalpha\_l](../Topic/isalpha,%20iswalpha,%20_isalpha_l,%20_iswalpha_l.md), [\_ismbcalnum, \_ismbcalnum\_l, \_ismbcalpha, \_ismbcalpha\_l, \_ismbcdigit, \_ismbcdigit\_l](../Topic/_ismbcalnum,%20_ismbcalnum_l,%20_ismbcalpha,%20_ismbcalpha_l,%20_ismbcdigit,%20_ismbcdigit_l.md)|Alfabético|[\<caps:sentence id\="tgt20" sentenceid\="7985fd1b5b2aeb907c06a172679a27b2" class\="tgtSentence"\>System::Char::IsLetter\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.char.isletter.aspx)|  
|[isascii isascii, iswascii](../c-runtime-library/reference/isascii-isascii-iswascii.md)|ASCII|[\<caps:sentence id\="tgt22" sentenceid\="7985fd1b5b2aeb907c06a172679a27b2" class\="tgtSentence"\>System::Char::IsLetter\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.char.isletter.aspx)|  
|[isblank, iswblank, \_isblank\_l, \_iswblank\_l](../c-runtime-library/reference/isblank-iswblank-isblank-l-iswblank-l.md), [\_ismbcsblank, \_ismbcsblank\_l](../c-runtime-library/reference/ismbcgraph-functions.md)|Em branco \(espaço ou guia horizontal\)|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[iscntrl, iswcntrl, \_iscntrl\_l, \_iswcntrl\_l](../c-runtime-library/reference/iscntrl-iswcntrl-iscntrl-l-iswcntrl-l.md)|Controle|[\<caps:sentence id\="tgt29" sentenceid\="9528bc8d4eee1fcafa3dca9e9901915d" class\="tgtSentence"\>System::Char::IsControl\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.char.iscontrol.aspx)|  
|[iscsym, iscsymf, iscsym, iswcsym, iscsymf, iswcsymf, iscsym\_l, iswcsym\_l, iscsymf\_l, iswcsymf\_l](../c-runtime-library/reference/iscsym-functions.md)|Letra, sublinhado ou dígito|[\<caps:sentence id\="tgt31" sentenceid\="9528bc8d4eee1fcafa3dca9e9901915d" class\="tgtSentence"\>System::Char::IsControl\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.char.iscontrol.aspx)|  
|[iscsym, iscsymf, iscsym, iswcsym, iscsymf, iswcsymf, iscsym\_l, iswcsym\_l, iscsymf\_l, iswcsymf\_l](../c-runtime-library/reference/iscsym-functions.md)|Letra ou sublinhado|[\<caps:sentence id\="tgt33" sentenceid\="9528bc8d4eee1fcafa3dca9e9901915d" class\="tgtSentence"\>System::Char::IsControl\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.char.iscontrol.aspx)|  
|[isdigit, iswdigit, \_isdigit\_l, \_iswdigit\_l](../c-runtime-library/reference/isdigit-iswdigit-isdigit-l-iswdigit-l.md), [\_ismbcalnum, \_ismbcalnum\_l, \_ismbcalpha, \_ismbcalpha\_l, \_ismbcdigit, \_ismbcdigit\_l](../Topic/_ismbcalnum,%20_ismbcalnum_l,%20_ismbcalpha,%20_ismbcalpha_l,%20_ismbcdigit,%20_ismbcdigit_l.md)|Dígito decimal|[\<caps:sentence id\="tgt36" sentenceid\="20b77d76c6cf167a186925e085420e65" class\="tgtSentence"\>System::Char::IsDigit\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.char.isdigit.aspx)|  
|[isgraph, iswgraph, \_isgraph\_l, \_iswgraph\_l](../Topic/isgraph,%20iswgraph,%20_isgraph_l,%20_iswgraph_l.md), [\_ismbcgraph, \_ismbcgraph\_l, \_ismbcprint, \_ismbcprint\_l, \_ismbcpunct, \_ismbcpunct\_l, \_ismbcblank, \_ismbcblank\_l, \_ismbcspace, \_ismbcspace\_l](../c-runtime-library/reference/ismbcgraph-functions.md)|Imprimível a não ser o espaço|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[islower, iswlower, \_islower\_l, \_iswlower\_l](../Topic/islower,%20iswlower,%20_islower_l,%20_iswlower_l.md), [\_ismbclower, \_ismbclower\_l, \_ismbcupper, \_ismbcupper\_l](../c-runtime-library/reference/ismbclower-ismbclower-l-ismbcupper-ismbcupper-l.md)|Minúsculas|[\<caps:sentence id\="tgt44" sentenceid\="5e79724bd080c040f5d77abaa610244d" class\="tgtSentence"\>System::Char::IsLower\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.char.islower.aspx)|  
|[\_ismbchira, \_ismbchira\_l, \_ismbckata, \_ismbckata\_l](../c-runtime-library/reference/ismbchira-ismbchira-l-ismbckata-ismbckata-l.md)|Hiragana|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_ismbchira, \_ismbchira\_l, \_ismbckata, \_ismbckata\_l](../c-runtime-library/reference/ismbchira-ismbchira-l-ismbckata-ismbckata-l.md)|Katakana|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_ismbclegal, \_ismbclegal\_l, \_ismbcsymbol, \_ismbcsymbol\_l](../c-runtime-library/reference/ismbclegal-ismbclegal-l-ismbcsymbol-ismbcsymbol-l.md)|Caractere válido de multibyte|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_ismbcl0, \_ismbcl0\_l, \_ismbcl1, \_ismbcl1\_l, \_ismbcl2, \_ismbcl2\_l](../c-runtime-library/reference/ismbcl0-ismbcl0-l-ismbcl1-ismbcl1-l-ismbcl2-ismbcl2-l.md)|Caractere de multibyte de nível 0 do Japão|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_ismbcl0, \_ismbcl0\_l, \_ismbcl1, \_ismbcl1\_l, \_ismbcl2, \_ismbcl2\_l](../c-runtime-library/reference/ismbcl0-ismbcl0-l-ismbcl1-ismbcl1-l-ismbcl2-ismbcl2-l.md)|Caractere de multibyte de nível 1 do Japão|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_ismbcl0, \_ismbcl0\_l, \_ismbcl1, \_ismbcl1\_l, \_ismbcl2, \_ismbcl2\_l](../c-runtime-library/reference/ismbcl0-ismbcl0-l-ismbcl1-ismbcl1-l-ismbcl2-ismbcl2-l.md)|Caractere de multibyte de nível 2 do Japão|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_ismbclegal, \_ismbclegal\_l, \_ismbcsymbol, \_ismbcsymbol\_l](../c-runtime-library/reference/ismbclegal-ismbclegal-l-ismbcsymbol-ismbcsymbol-l.md)|Caractere não alfanumérico de multibyte|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[isprint, iswprint, \_isprint\_l, \_iswprint\_l](../c-runtime-library/reference/isprint-iswprint-isprint-l-iswprint-l.md), [\_ismbcgraph, \_ismbcgraph\_l, \_ismbcprint, \_ismbcprint\_l, \_ismbcpunct, \_ismbcpunct\_l, \_ismbcblank, \_ismbcblank\_l, \_ismbcspace, \_ismbcspace\_l](../c-runtime-library/reference/ismbcgraph-functions.md)|Para impressão|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[ispunct, iswpunct, \_ispunct\_l, \_iswpunct\_l](../c-runtime-library/reference/ispunct-iswpunct-ispunct-l-iswpunct-l.md), [\_ismbcgraph, \_ismbcgraph\_l, \_ismbcprint, \_ismbcprint\_l, \_ismbcpunct, \_ismbcpunct\_l, \_ismbcblank, \_ismbcblank\_l, \_ismbcspace, \_ismbcspace\_l](../c-runtime-library/reference/ismbcgraph-functions.md)|Pontuação|[\<caps:sentence id\="tgt80" sentenceid\="d38bbde5482b110a63876458567db603" class\="tgtSentence"\>System::Char::IsPunctuation\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.char.ispunctuation.aspx)|  
|[isspace, iswspace, \_isspace\_l, \_iswspace\_l](../c-runtime-library/reference/isspace-iswspace-isspace-l-iswspace-l.md), [\_ismbcgraph, \_ismbcgraph\_l, \_ismbcprint, \_ismbcprint\_l, \_ismbcpunct, \_ismbcpunct\_l, \_ismbcblank, \_ismbcblank\_l, \_ismbcspace, \_ismbcspace\_l](../c-runtime-library/reference/ismbcgraph-functions.md)|Espaço em branco|[\<caps:sentence id\="tgt83" sentenceid\="acbb8b5269b25caa0be79d70895dc079" class\="tgtSentence"\>System::Char::IsWhiteSpace\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.char.iswhitespace.aspx)|  
|[Isupper, iswupper](../Topic/isupper,%20_isupper_l,%20iswupper,%20_iswupper_l.md), [\_ismbclower, \_ismbclower\_l, \_ismbcupper, \_ismbcupper\_l](../c-runtime-library/reference/ismbclower-ismbclower-l-ismbcupper-ismbcupper-l.md)|Maiúsculas|[\<caps:sentence id\="tgt86" sentenceid\="7f17c3dfa91d5cdf120546eae2131f1f" class\="tgtSentence"\>System::Char::IsUpper\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.char.isupper.aspx)|  
|[\_isctype, iswctype, \_isctype\_l, \_iswctype\_l](../Topic/_isctype,%20iswctype,%20_isctype_l,%20_iswctype_l.md)|A propriedade especificada pelo argumento `desc`|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[isxdigit, iswxdigit, \_isxdigit\_l, \_iswxdigit\_l](../c-runtime-library/reference/isxdigit-iswxdigit-isxdigit-l-iswxdigit-l.md)|Dígito hexadecimal|[\<caps:sentence id\="tgt92" sentenceid\="ce7b0e5c510cf706d10a80a8594068ce" class\="tgtSentence"\>System::Char::IsNumber\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.char.isnumber.aspx)|  
|[\_mbclen, mblen, \_mblen\_l](../c-runtime-library/reference/mbclen-mblen-mblen-l.md)|Retorna o tamanho do caractere multibyte válido; o resultado depende da configuração da categoria `LC_CTYPE` da localidade atual|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
  
## Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)