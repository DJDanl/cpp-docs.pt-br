---
title: Unicode e Multibyte Character Set (MBCS) suporte | Microsoft Docs
ms.custom: ''
ms.date: 1/09/2017
ms.technology:
- cpp-mfc
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- MFC [C++], character set support
- MBCS [C++], strings and MFC support
- strings [C++], MBCS support in MFC
- character sets [C++], multibyte
- Unicode [C++], MFC strings
- Unicode [C++], string objects
- strings [C++], Unicode
- strings [C++], character set support
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8492e4a6777e4d609e3b457cfc77d1b8a691eed3
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="unicode-and-multibyte-character-set-mbcs-support"></a>Suporte a Unicode e Multibyte Character Set (MBCS)

Alguns idiomas, por exemplo, japonês e chinês, têm conjuntos de caracteres grandes. Para dar suporte à programação para esses mercados, a Microsoft Foundation Class Library (MFC) permite duas abordagens diferentes para lidar com conjuntos de caracteres grandes:

- [Unicode](#mfc-support-for-unicode-strings), `wchar_t` com base em caracteres de largura e cadeias de caracteres codificadas como UTF-16.

- [Conjuntos de caracteres multibyte (MBCS)](#mfc-support-for-mbcs-strings), `char` com base em caracteres de byte duplo ou único e cadeias de caracteres codificadas em um conjunto de caracteres específicas da localidade.

As bibliotecas MFC Unicode para todos os novos desenvolvimentos tem recomendadas da Microsoft e as bibliotecas MBCS foram preteridas no Visual Studio 2013 e Visual Studio 2015. Esse não é mais o caso. Os avisos de depreciação MBCS foram removidos do Visual Studio de 2017.

## <a name="mfc-support-for-unicode-strings"></a>Suporte MFC para cadeias de caracteres Unicode

A biblioteca de classe MFC inteira condicionalmente está habilitada para caracteres Unicode e cadeias de caracteres armazenadas em caracteres largos como UTF-16. Em particular, a classe [CString](../atl-mfc-shared/reference/cstringt-class.md) está habilitado para Unicode.

Esses biblioteca, depurador e arquivos DLL são usados para oferecer suporte a Unicode em MFC:

|||||
|-|-|-|-|
|UAFXCW.LIB|UAFXCW. PDB|UAFXCWD.LIB|UAFXCWD. PDB|
|MFC*versão*U.LIB|MFC*versão*U.PDB|MFC*versão*U.DLL|MFC*versão*UD. LIB|
|MFC*versão*UD. PDB|MFC*versão*UD. DLL|MFCS*versão*U.LIB|MFCS*versão*U.PDB|
|MFCS*versão*UD. LIB|MFCS*versão*UD. PDB|MFCM*versão*U.LIB|MFCM*versão*U.PDB|
|MFCM*versão*U.DLL|MFCM*versão*UD. LIB|MFCM*versão*UD. PDB|MFCM*versão*UD. DLL|

(*versão* representa o número de versão do arquivo; por exemplo, '140' significa versão 14.0.)

`CString` se baseia o `TCHAR` tipo de dados. Se o símbolo `_UNICODE` está definido para uma compilação do seu programa, `TCHAR` é definido como tipo `wchar_t`, um tipo de codificação de caracteres de 16 bits. Caso contrário, `TCHAR` é definido como `char`, a codificação de caracteres de 8 bits normal. Portanto, em Unicode, um `CString` é composto de caracteres de 16 bits. Sem Unicode, ele é composto de caracteres do tipo `char`.

A programação Unicode completa do seu aplicativo, você também deve:

- Use o `_T` macro condicionalmente código cadeias de caracteres literais para ser portátil para Unicode.

- Ao passar cadeias de caracteres, preste atenção se os argumentos da função exigir um comprimento de caracteres ou um tamanho em bytes. A diferença é importante se você estiver usando cadeias de caracteres Unicode.

- Use versões portátil das funções de manipulação de cadeia de caracteres de tempo de execução C.

- Use os seguintes tipos de dados de caracteres e ponteiros de caractere:

   - Use `TCHAR` onde você usaria `char`.

   - Use `LPTSTR` onde você usaria `char*`.

   - Use `LPCTSTR` onde você usaria `const char*`. `CString` fornece o operador `LPCTSTR` para converter entre `CString` e `LPCTSTR`.

`CString` também fornece construtores com reconhecimento de Unicode, operadores de atribuição e operadores de comparação.

O [referência da biblioteca de tempo de execução](../c-runtime-library/c-run-time-library-reference.md) define versões portátil de todas as suas funções de manipulação de cadeia de caracteres. Para obter mais informações, consulte a categoria [internacionalização](../c-runtime-library/internationalization.md).

## <a name="mfc-support-for-mbcs-strings"></a>Suporte MFC para cadeias de caracteres MBCS

A biblioteca de classes também é habilitada para conjuntos de caracteres multibyte, mas somente para o caractere de byte duplo conjuntos (DBCS).

Em um conjunto de caracteres multibyte, um caractere pode ser um ou dois bytes de largura. Se for ampla de dois bytes, o primeiro byte é um "byte inicial" especial que é escolhido de um intervalo específico, dependendo de qual código de página está em uso. Juntos, o cliente potencial e "bytes de trilha" Especifica uma codificação de caracteres exclusiva.

Se o símbolo `_MBCS` está definido para uma compilação do seu programa, o tipo `TCHAR`, no qual `CString` se baseia, mapeia para `char`. Cabe a você para determinar quais bytes em um `CString` são bytes de cliente potencial e quais são os bytes de trilha. A biblioteca de tempo de execução do C fornece funções para ajudar a determinar isso.

Em DBCS, uma determinada cadeia de caracteres pode conter todos os caracteres de ANSI de byte único, todos os caracteres de byte duplo ou uma combinação dos dois. Essas possibilidades requerem cuidado especial ao analisar cadeias de caracteres. Isso inclui `CString` objetos.

> [!NOTE]
> Serialização de cadeia de caracteres Unicode em MFC pode ler cadeias de caracteres Unicode e MBCS, independentemente de qual versão do aplicativo que você está executando. Os arquivos de dados são portáveis entre versões Unicode e MBCS do seu programa.

`CString` funções de membro usam versões especiais "texto genérico" as tempo de execução de funções de C que eles chamam, ou usam funções de reconhecimento de Unicode. Portanto, por exemplo, se um `CString` normalmente seria chamada de função `strcmp`, ele chama a função de texto genérico correspondente `_tcscmp` em vez disso. Dependendo de como os símbolos `_MBCS` e `_UNICODE` são definidos, `_tcscmp` mapeia da seguinte maneira:

|||
|-|-|
|`_MBCS` definido|`_mbscmp`|
|`_UNICODE` definido|`wcscmp`|
|Nenhum símbolo definido|`strcmp`|

> [!NOTE]
> Os símbolos `_MBCS` e `_UNICODE` são mutuamente exclusivos.

Mapeamentos de função de texto genérico de todas as rotinas de manipulação de cadeia de caracteres de tempo de execução são discutidos em [referência de biblioteca de tempo de execução do C](../c-runtime-library/c-run-time-library-reference.md). Para obter uma lista, consulte [internacionalização](../c-runtime-library/internationalization.md).

Da mesma forma, `CString` métodos são implementados usando mapeamentos de tipo de dados genéricos. Para habilitar MBCS e Unicode, usa MFC `TCHAR` para `char` ou `wchar_t`, `LPTSTR` para `char*` ou `wchar_t*`, e `LPCTSTR` para `const char*` ou `const wchar_t*`. Eles garantem os mapeamentos corretos para MBCS ou Unicode.

## <a name="see-also"></a>Consulte também

[Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)  
[Manipulação de cadeias de caracteres](../c-runtime-library/string-manipulation-crt.md)  
