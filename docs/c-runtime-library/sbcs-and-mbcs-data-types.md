---
title: "Tipos de dados SBCS e MBCS | Microsoft Docs"
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
  - "MBCS"
  - "SBCS"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "tipos de dados SBCS e MBCS"
  - "tipos de dados [C] MBCS e SBCS"
ms.assetid: 4c3ef9da-e397-48d4-800e-49dba36db171
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Tipos de dados SBCS e MBCS
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Qualquer rotina de biblioteca de tempo de execução do Microsoft `MBCS` que tratar apenas um caracteres multibyte ou um byte de um caracteres multibyte espera que um argumento de `unsigned``int` \(onde 0x00 \<\= valor \<de caractere 0xFFFF \= e \= valor \<\<de 0x00 de bytes \= 0xFF\).  Uma rotina de `MBCS` que trata bytes ou caracteres multibyte em um contexto de cadeia de caracteres espera uma cadeia de caracteres de multibyte\- caractere ser representada como um ponteiro de `unsigned``char` .  
  
> [!CAUTION]
>  Cada byte de um caracteres multibyte pode ser representado em `char`de 8 bits.  No entanto, `SBCS` ou um caractere de byte único de `MBCS` do tipo `char` com um valor maior que 0x7F são negativo.  Quando tal caracteres são convertidos diretamente a `int` ou a `long`, o resultado sinal\- será estendido pelo compilador e em virtude disso pode gerar resultados inesperados.  
  
 Em virtude disso é melhor representar um byte de um caracteres multibyte como `unsigned char`de 8 bits.  Ou, para evitar um resultado negativo, para converter somente um caractere de byte único tipo de `char` a `unsigned char` convertê\-los antes da `int` ou a `long`.  
  
 Como algumas funções de cadeia de caracteres\- manipulação de `SBCS` obtêm parâmetros \(assinado\) de `char*` , um aviso do compilador de incompatibilidade ocorrerá quando `_MBCS` é definido.  Há três maneiras de evitar esse aviso, listados em ordem de eficiência:  
  
1.  Use as funções embutidas “tipo seguras” em. TCHAR.H.  Este é o comportamento padrão.  
  
2.  Use “direcionam macros” em TCHAR.H definindo `_MB_MAP_DIRECT` na linha de comando.  Se você fizer isso, você deve corresponder manualmente tipos.  Esse é o método mais rápido mas não é do tipo seguro.  
  
3.  Use funções da biblioteca estaticamente vinculadas “tipo seguras” em. TCHAR.H.  Para fazer isso, defina `_NO_INLINING` constante na linha de comando.  Esse é o método mais lento, mas o tipo mais segura.  
  
## Consulte também  
 [Internacionalização](../c-runtime-library/internationalization.md)   
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)