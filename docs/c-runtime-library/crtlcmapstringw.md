---
title: "__crtLCMapStringW | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "__crtLCMapStringW"
apilocation: 
  - "msvcr90.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr100.dll"
  - "msvcrt.dll"
  - "msvcr120.dll"
  - "msvcr110.dll"
  - "msvcr80.dll"
apitype: "DLLExport"
f1_keywords: 
  - "__crtLCMapStringW"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__crtLCMapStringW"
ms.assetid: 45b4ac0e-438c-4fa3-b4d1-34195f4467d9
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __crtLCMapStringW
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Mapeia uma seqüência de caracteres para outro, executando uma transformação depende da localidade especificada. Essa função também pode ser usada para gerar uma chave de classificação para a cadeia de caracteres de entrada.  
  
## Sintaxe  
  
```cpp  
int __crtLCMapStringW(  
   LCID    Locale,  
   DWORD   dwMapFlags,  
   LPCWSTR lpSrcStr,  
   int     cchSrc,  
   LPWSTR  lpDestStr,  
   int     cchDest)  
```  
  
#### Parâmetros  
 `Locale`  
 Identificador de localidade. A localidade fornece um contexto para o mapeamento de cadeia de caracteres ou a geração de chaves de classificação. Um aplicativo pode usar o `MAKELCID` macro para criar um identificador de localidade.  
  
 `dwMapFlags`  
 O tipo de transformação a ser usado durante a geração de chave mapeamento ou classificação de cadeia de caracteres.  
  
 `lpSrcStr`  
 Ponteiro para uma cadeia de caracteres de origem que a função de mapas ou usa para geração de chave de classificação. Esse parâmetro é considerado como uma cadeia de caracteres Unicode.  
  
 `cchSrc`  
 Tamanho, em caracteres, da cadeia de caracteres apontada pelo `lpSrcStr` parâmetro. Essa contagem pode incluir o terminador nulo ou não incluí\-lo.  
  
 Um `cchSrc` valor – 1 Especifica que a cadeia de caracteres apontada por `lpSrcStr` é terminada em nulo. Se esse for o caso, e essa função está sendo usada no modo de mapeamento de cadeia de caracteres, a função calcula o comprimento da cadeia de caracteres em si e null\-encerra a cadeia de caracteres mapeada armazenada em `*lpDestStr`.  
  
 `lpDestStr`  
 Long ponteiro para um buffer no qual a função armazena a chave de cadeia de caracteres ou classificação mapeada.  
  
 `cchDest`  
 Tamanho, em caracteres, do buffer apontada por `lpDestStr`.  
  
## Valor de retorno  
 Se o valor de `cchDest` é diferente de zero, o número de caracteres ou bytes se `LCMAP_SORTKEY` for especificado, gravada para o buffer indica êxito. Essa contagem inclui espaço para um terminador nulo.  
  
 Se o valor de `cchDest` for zero, o tamanho do buffer em caracteres ou bytes se `LCMAP_SORTKEY` for especificado, necessário para receber o traduzido chave de cadeia de caracteres ou classificação indica êxito. Esse tamanho inclui espaço para um terminador nulo.  
  
 Zero indica falha. Para obter mais informações sobre o erro, chame o `GetLastError` função.  
  
## Comentários  
 Se `cchSrc` for maior que zero e `lpSrcStr` é uma cadeia de caracteres terminada em nulo, `__crtLCMapStringW` define `cchSrc` para o comprimento da cadeia de caracteres. Em seguida, `__crtLCMapStringW` chama a versão de cadeia de caracteres larga \(Unicode\) do `LCMapString` função com os parâmetros especificados. Para obter mais informações sobre os parâmetros e valor de retorno dessa função, consulte o `LCMapString` funcionar a [biblioteca MSDN](http://go.microsoft.com/fwlink/?linkID=150542).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|\_\_crtLCMapStringW|awint.h|