---
title: "Usando mapeamentos de texto gen&#233;rico | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "_UNICODE"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Tipo de dados _MBCS"
  - "Tipo _T"
  - "Tipo _TCHAR"
  - "Tipo _TEXT"
  - "Tipo _TINT"
  - "Tipo _TSCHAR"
  - "Tipo _TUCHAR"
  - "Tipo _TXCHAR"
  - "Constante _UNICODE"
  - "tipos de dados de texto genérico"
  - "mapeamentos de texto genérico"
  - "mapeamentos, texto genérico"
  - "Tipo de dados MBCS"
  - "Tipo T"
  - "Tipo TCHAR"
  - "Tipos de dados TCHAR.H, mapeamentos definidos em"
  - "Tipo TEXT"
  - "Tipo TINT"
  - "Tipo TSCHAR"
  - "Tipo TUCHAR"
  - "Tipo TXCHAR"
  - "Constante UNICODE"
ms.assetid: 2848121c-e51f-4b9b-a2e6-833ece4b0cb3
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Usando mapeamentos de texto gen&#233;rico
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Para simplificar o desenvolvimento do código para vários data marts internacionais, a biblioteca de tempo de execução do Microsoft fornece mapeamentos específicos da microsoft “genérico\- texto” para muitos tipos de dados, rotinas, e outros objetos.  Esses mapeamentos são definidos em TCHAR.H.  Você pode usar esses mapeamentos de nome para escrever o código genérico que pode ser compilado para qualquer um dos três tipos de conjuntos de caracteres: SBCS ASCII \(\), MBCS, ou Unicode, como uma constante manifesta você define usando uma instrução de `#define` .  Os mapeamentos de Genérico\- texto são as extensões da Microsoft que não são ANSI compatível.  
  
### Políticas de pré\-processador para mapeamentos de Genérico\- texto  
  
|\#define|Versão compilada|Exemplo|  
|--------------|----------------------|-------------|  
|`_UNICODE`|Ampla caractere Unicode \(\)|mapas de`_tcsrev` a `_wcsrev`|  
|`_MBCS`|Multibyte\-caractere|mapas de`_tcsrev` a `_mbsrev`|  
|Nenhum \(a opção: nem `_UNICODE` ou `_MBCS` definidas\)|SBCS \(ASCII\)|mapas de`_tcsrev` a `strrev`|  
  
 Por exemplo, a função `_tcsrev`de genérico\- texto, definido em TCHAR.H, mapas na `mbsrev` se `MBCS` foi definido em seu programa, ou a `_wcsrev` se `_UNICODE` foi definido.  Se não mapas de `_tcsrev` a `strrev`.  
  
 O tipo de dados `_TCHAR`de genérico\- texto, também definido em TCHAR.H, em mapa para digitar `char` se `_MBCS` é definido, digite `wchar_t` se `_UNICODE` é definido, e digite `char` se nenhuma constante é definida.  Outros mapeamentos de tipo de dados são fornecidos em TCHAR.H para conveniência de programação, mas `_TCHAR` é o tipo que é mais útil.  
  
### Mapeamentos de tipo de dados de Genérico\- texto  
  
|Nome do tipo de dados de Genérico\- texto|SBCS \(\_UNICODE, \_MBCS não definidos\)|\_MBCS definido|\_UNICODE definido|  
|-----------------------------------------------|----------------------------------------------|---------------------|------------------------|  
|`_TCHAR`|`char`|`char`|`wchar_t`|  
|`_TINT`|`int`|`int`|`wint_t`|  
|`_TSCHAR`|`signed char`|`signed char`|`wchar_t`|  
|`_TUCHAR`|`unsigned char`|`unsigned char`|`wchar_t`|  
|`_TXCHAR`|`char`|`unsigned char`|`wchar_t`|  
|`_T` ou `_TEXT`|Nenhum efeito \(cancelado por pré\-processador\)|Nenhum efeito \(cancelado por pré\-processador\)|`L` \(converte após o caractere ou cadeia de caracteres à sua contraparte Unicode\)|  
  
 Para obter uma lista completa de mapeamentos de genérico\- texto rotinas, variáveis, e outros objetos, consulte [Mapeamentos de Genérico\- texto](../c-runtime-library/generic-text-mappings.md).  
  
 Estes fragmentos de código a seguir ilustram o uso de `_TCHAR` e de `_tcsrev` para mapear para o MBCS, para Unicode, e a modelos de SBCS.  
  
```  
_TCHAR *RetVal, *szString;  
RetVal = _tcsrev(szString);  
```  
  
 Se `MBCS` foi definido, o pré\-processador mapeia o fragmento anterior ao seguinte código:  
  
```  
char *RetVal, *szString;  
RetVal = _mbsrev(szString);  
```  
  
 Se `_UNICODE` foi definido, o pré\-processador mapeia o mesmo fragmento o seguinte código:  
  
```  
wchar_t *RetVal, *szString;  
RetVal = _wcsrev(szString);  
```  
  
 Se nem nem `_MBCS``_UNICODE` foram definidas, o pré\-processador mapeia o fragmento ao código ASCII de byte único, como segue:  
  
```  
char *RetVal, *szString;  
RetVal = strrev(szString);  
```  
  
 Assim, você pode escrever manter, e criar um único arquivo de código\-fonte para executar com rotinas que são específicas a qualquer um dos três tipos de conjuntos de caracteres.  
  
 **FINALIZAR Específico da Microsoft**  
  
## Consulte também  
 [Mapeamentos de texto genérico](../c-runtime-library/generic-text-mappings.md)   
 [Mapeamentos de tipo de dados](../c-runtime-library/data-type-mappings.md)   
 [Constante e mapeamentos de variável global](../c-runtime-library/constant-and-global-variable-mappings.md)   
 [Mapeamentos de rotina](../c-runtime-library/routine-mappings.md)   
 [Um programa de texto genérico de exemplo](../c-runtime-library/a-sample-generic-text-program.md)