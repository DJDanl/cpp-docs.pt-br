---
title: Unicode e Multibyte Character Set (MBCS) suporte | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs: C++
helpviewer_keywords:
- MFC [C++], character set support
- MBCS [C++], strings and MFC support
- strings [C++], MBCS support in MFC
- character sets [C++], multibyte
- Unicode [C++], MFC strings
- Unicode [C++], string objects
- strings [C++], Unicode
- strings [C++], character set support
ms.assetid: 44b3193b-c92d-40c5-9fa8-5774da303cce
caps.latest.revision: "17"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ea35f36012eb893d8784c626c533690e97b517e5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="unicode-and-multibyte-character-set-mbcs-support"></a>Suporte a Unicode e Multibyte Character Set (MBCS)
Alguns idiomas, por exemplo, japonês e chinês, têm conjuntos de caracteres grandes. Para dar suporte à programação para esses mercados, a Microsoft Foundation Class Library (MFC) está habilitado para duas abordagens diferentes para lidar com conjuntos de caracteres grandes:  
  
-   [Unicode](#_core_mfc_support_for_unicode_strings)  
  
-   [Conjuntos de caracteres multibyte (MBCS)](#_core_mfc_support_for_mbcs_strings)  
  
 Você deve usar Unicode para todos os novos desenvolvimentos.  
  
##  <a name="_core_mfc_support_for_unicode_strings"></a>Suporte MFC para cadeias de caracteres Unicode  
 A biblioteca de classes completa condicionalmente está habilitada para cadeias de caracteres e caracteres Unicode. Em particular, a classe [CString](../atl-mfc-shared/reference/cstringt-class.md) está habilitado para Unicode.  
  
|||||  
|-|-|-|-|  
|UAFXCW. LIB|UAFXCW. PDB|UAFXCWD. LIB|UAFXCWD. PDB|  
|MFC*xx*U.LIB|MFC*xx*U.PDB|MFC*xx*U.DLL|MFC*xx*UD. LIB|  
|MFC*xx*UD. PDB|MFC*xx*UD. DLL|MFCS*xx*U.LIB|MFCS*xx*U.PDB|  
|MFCS*xx*UD. LIB|MFCS*xx*UD. PDB|MFCM*xx*U.LIB|MFCM*xx*U.PDB|  
|MFCM*xx*U.DLL|MFCM*xx*UD. LIB|MFCM*xx*UD. PDB|MFCM*xx*UD. DLL|  
  
 (*xx* representa o número de versão do arquivo; por exemplo, '80' significa versão 8.0.)  
  
 `CString`se baseia o `TCHAR` tipo de dados. Se o símbolo `_UNICODE` está definido para uma compilação do seu programa, `TCHAR` é definido como tipo `wchar_t`, um tipo de codificação de caracteres de 16 bits. Caso contrário, `TCHAR` é definido como `char`, a codificação de caracteres de 8 bits normal. Portanto, em Unicode, um `CString` é composto de caracteres de 16 bits. Sem Unicode, ele é composto de caracteres do tipo `char`.  
  
 A programação Unicode completa do seu aplicativo, você também deve:  
  
-   Use o `_T` macro condicionalmente código cadeias de caracteres literais para ser portátil para Unicode.  
  
-   Ao passar cadeias de caracteres, preste atenção se os argumentos da função exigir um comprimento de caracteres ou um tamanho em bytes. A diferença é importante se você estiver usando cadeias de caracteres Unicode.  
  
-   Use versões portátil das funções de manipulação de cadeia de caracteres de tempo de execução C.  
  
-   Use os seguintes tipos de dados de caracteres e ponteiros de caractere:  
  
    -   `TCHAR`Quando você usa `char`.  
  
    -   `LPTSTR`Quando você usa `char*`.  
  
    -   `LPCTSTR`Quando você usa `const char*`. `CString`fornece o operador `LPCTSTR` para converter entre `CString` e `LPCTSTR`.  
  
 `CString`também fornece construtores com reconhecimento de Unicode, operadores de atribuição e operadores de comparação.  
  
 Para obter informações sobre a programação de Unicode, consulte [tópicos Unicode](../mfc/unicode-in-mfc.md). O [referência da biblioteca de tempo de execução](../c-runtime-library/c-run-time-library-reference.md) define versões portátil de todas as suas funções de manipulação de cadeia de caracteres. Consulte a categoria [internacionalização](../c-runtime-library/internationalization.md).  
  
##  <a name="_core_mfc_support_for_mbcs_strings"></a>Suporte MFC para cadeias de caracteres MBCS  
  
 A biblioteca de classes também é habilitada para conjuntos de caracteres multibyte, mas somente para o caractere de byte duplo conjuntos (DBCS).  
  
 Em um conjunto de caracteres multibyte, um caractere pode ser um ou dois bytes de largura. Se for ampla de dois bytes, o primeiro byte é um "byte inicial" especial que é escolhido de um intervalo específico, dependendo de qual código de página está em uso. Juntos, o cliente potencial e "bytes de trilha" Especifica uma codificação de caracteres exclusiva.  
  
 Se o símbolo `_MBCS` está definido para uma compilação do seu programa, o tipo `TCHAR`, no qual `CString` se baseia, mapeia para `char`. Cabe a você para determinar quais bytes em um `CString` são bytes de cliente potencial e quais são os bytes de trilha. A biblioteca de tempo de execução do C fornece funções para ajudar a determinar isso.  
  
 Em DBCS, uma determinada cadeia de caracteres pode conter todos os caracteres de ANSI de byte único, todos os caracteres de byte duplo ou uma combinação dos dois. Essas possibilidades requerem cuidado especial ao analisar cadeias de caracteres. Isso inclui `CString` objetos.  
  
> [!NOTE]
>  Serialização de cadeia de caracteres Unicode em MFC pode ler cadeias de caracteres Unicode e MBCS, independentemente de qual versão do aplicativo que você está executando. Os arquivos de dados são portáveis entre versões Unicode e MBCS do seu programa.  
  
 `CString`funções de membro usam versões especiais "texto genérico" as tempo de execução de funções de C que eles chamam, ou usam funções de reconhecimento de Unicode. Portanto, por exemplo, se um `CString` normalmente seria chamada de função `strcmp`, ele chama a função de texto genérico correspondente `_tcscmp` em vez disso. Dependendo de como os símbolos `_MBCS` e `_UNICODE` são definidos, `_tcscmp` mapeia da seguinte maneira:  
  
|||  
|-|-|  
|`_MBCS`definido|`_mbscmp`|  
|`_UNICODE`definido|`wcscmp`|  
|Nenhum símbolo definido|`strcmp`|  
  
> [!NOTE]
>  Os símbolos `_MBCS` e `_UNICODE` são mutuamente exclusivos.  
  
 Mapeamentos de função de texto genérico de todas as rotinas de manipulação de cadeia de caracteres de tempo de execução são discutidos em [referência de biblioteca de tempo de execução do C](../c-runtime-library/c-run-time-library-reference.md). Em particular, consulte [internacionalização](../c-runtime-library/internationalization.md).  
  
 Da mesma forma, `CString` métodos são implementados usando mapeamentos de tipo de dados "genérico". Para habilitar MBCS e Unicode, usa MFC `TCHAR` para `char`, `LPTSTR` para `char*`, e `LPCTSTR` para `const char*`. Eles garantem os mapeamentos corretos para MBCS ou Unicode.  
  
## <a name="see-also"></a>Consulte também  
 [Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)   
 [Manipulação de cadeias de caracteres](../c-runtime-library/string-manipulation-crt.md)

