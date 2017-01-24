---
title: "_ismbslead, _ismbstrail, _ismbslead_l, _ismbstrail_l | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_ismbstrail"
  - "_ismbslead_l"
  - "_ismbslead"
  - "_ismbstrail_l"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-multibyte-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_ismbslead"
  - "ismbs"
  - "ismbslead_l"
  - "_ismbs"
  - "ismbstrail_l"
  - "ismbslead"
  - "_ismbstrail"
  - "_ismbstrail_l"
  - "ismbstrail"
  - "_ismbslead_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _ismbslead"
  - "Função _ismbslead_l"
  - "Função _ismbstrail"
  - "Função _ismbstrail_l"
  - "Função ismbslead"
  - "Função ismbslead_l"
  - "Função ismbstrail"
  - "Função ismbstrail_l"
ms.assetid: 86d2cd7a-3cff-443a-b713-14cc17a231e9
caps.latest.revision: 22
caps.handback.revision: 22
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _ismbslead, _ismbstrail, _ismbslead_l, _ismbstrail_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Executa os testes contextuais para bytes de cadeia de caracteres multibyte líder e trilha e determina se um ponteiro de determinada subcadeia de caracteres aponta para um byte inicial ou um byte final.  
  
> [!IMPORTANT]
>  Essa API não pode ser usada em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  Para obter mais informações, consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _ismbslead(  
   const unsigned char *str,  
   const unsigned char *current   
);  
int _ismbstrail(  
   const unsigned char *str,  
   const unsigned char *current   
);  
int _ismbslead_l(  
   const unsigned char *str,  
   const unsigned char *current,  
   _locale_t locale  
);  
int _ismbstrail_l(  
   const unsigned char *str,  
   const unsigned char *current,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `str`  
 Ponteiro para o início da cadeia de caracteres ou o anterior byte conhecidos.  
  
 `current`  
 Ponteiro para a posição na cadeia de caracteres a ser testada.  
  
 `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 `_ismbslead` retornará \-1 se o caractere é um byte e `_ismbstrail` retorna – 1 se o caractere é um byte final.  Se as cadeias de caracteres de entrada são válidas, mas não são um byte inicial ou byte final, essas funções retornam zero.  Se o argumento for `NULL`, o manipulador de parâmetro inválido é chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções retornarão `NULL` e definirão `errno` para `EINVAL`.  
  
## Comentários  
 `_ismbslead` e `_ismbstrail` são mais lentos que o `_ismbblead` e `_ismbbtrail` versões porque eles consideram o contexto de cadeia de caracteres.  
  
 As versões dessas funções que têm o `_l` sufixo são idênticas, exceto que para seu comportamento dependente de localidade que eles usam a localidade que é passada em vez da localidade atual.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_ismbslead`|\< mbctype.h \> ou \< mbstring.h \>|\< CType \> \* \< Limits. h \>, \< stdlib. h \>|  
|`_ismbstrail`|\< mbctype.h \> ou \< mbstring.h \>|\< CType \> \* \< Limits. h \>, \< stdlib. h \>|  
|`_ismbslead_l`|\< mbctype.h \> ou \< mbstring.h \>|\< CType \> \* \< Limits. h \>, \< stdlib. h \>|  
|`_ismbstrail_l`|\< mbctype.h \> ou \< mbstring.h \>|\< CType \> \* \< Limits. h \>, \< stdlib. h \>|  
  
 \* Para constantes de manifesto para as condições de teste.  
  
 Para obter mais informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Classificação de caractere](../../c-runtime-library/character-classification.md)   
 [Rotinas \_ismbc](../../c-runtime-library/ismbc-routines.md)   
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)   
 [Rotinas \_ismbb](../../c-runtime-library/ismbb-routines.md)