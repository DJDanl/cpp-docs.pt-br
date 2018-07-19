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
ms.openlocfilehash: 6e9d212e74f77d21efa1b2ed030f8a1446d111fc
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37882943"
---
# <a name="unicode-and-multibyte-character-set-mbcs-support"></a>Suporte a Unicode e Multibyte Character Set (MBCS)

Algumas linguagens, por exemplo, japonês e chinês, tem conjuntos de caracteres grandes. Para dar suporte à programação para esses mercados, o Microsoft Foundation Class Library (MFC) permite que duas abordagens diferentes para lidar com conjuntos de caracteres grandes:

- [Unicode](#mfc-support-for-unicode-strings), `wchar_t` baseados em caracteres largos e cadeias de caracteres codificadas como UTF-16.

- [Conjuntos de caracteres multibyte (MBCS)](#mfc-support-for-mbcs-strings), **char** baseados em caracteres únicos ou de dois bytes e cadeias de caracteres codificadas em um conjunto de caracteres específicas da localidade.

A Microsoft recomendou as bibliotecas MFC Unicode para todos os novos desenvolvimentos e as bibliotecas MBCS foram preteridas no Visual Studio 2013 e Visual Studio 2015. Esse não é mais o caso. Os avisos de depreciação de MBCS no Visual Studio 2017 foram removidos.

## <a name="mfc-support-for-unicode-strings"></a>Suporte MFC para cadeias de caracteres Unicode

A biblioteca de classes do MFC toda condicionalmente está habilitada para caracteres Unicode e cadeias de caracteres armazenadas em caracteres largos como UTF-16. Em particular, a classe [CString](../atl-mfc-shared/reference/cstringt-class.md) está habilitado para Unicode.

Esses library, depurador e arquivos DLL são usados para dar suporte a Unicode em MFC:

|||||
|-|-|-|-|
|UAFXCW.LIB|UAFXCW. PDB|UAFXCWD.LIB|UAFXCWD. PDB|
|MFC*versão*U.LIB|MFC*versão*U.PDB|MFC*versão*U.DLL|MFC*versão*UD. LIB|
|MFC*versão*UD. PDB|MFC*versão*UD. DLL|MFCS*versão*U.LIB|MFCS*versão*U.PDB|
|MFCS*versão*UD. LIB|MFCS*versão*UD. PDB|MFCM*versão*U.LIB|MFCM*versão*U.PDB|
|MFCM*versão*U.DLL|MFCM*versão*UD. LIB|MFCM*versão*UD. PDB|MFCM*versão*UD. DLL|

(*versão* representa o número de versão do arquivo; por exemplo, '140' significa versão 14.0.)

`CString` se baseia no tipo de dados TCHAR. Se o Unicode de símbolo é definido para uma compilação do seu programa, TCHAR é definida como tipo `wchar_t`, um tipo de codificação de caracteres de 16 bits. Caso contrário, TCHAR é definido como **char**, a codificação de caracteres de 8 bits normal. Portanto, em Unicode, um `CString` é composto de caracteres de 16 bits. Sem Unicode, ele é composto de caracteres do tipo **char**.

Programação de Unicode completa do seu aplicativo, você também deve:

- Use a macro t para condicionalmente código cadeias de caracteres literais para ser portátil para Unicode.

- Ao passar cadeias de caracteres, preste atenção se os argumentos da função exigir um comprimento em caracteres ou um tamanho em bytes. A diferença é importante se você estiver usando cadeias de caracteres Unicode.

- Use versões portáveis das funções de manipulação de cadeia de caracteres de tempo de execução C.

- Use os seguintes tipos de dados de caracteres e ponteiros de caractere:

   - Usar TCHAR onde você usaria **char**.

   - Usar LPTSTR onde você usaria **char\***.

   - Usar LPCTSTR onde você usaria **const char\***. `CString` fornece o operador LPCTSTR para converter entre `CString` e LPCTSTR.

`CString` também fornece reconhecimento Unicode construtores, operadores de atribuição e operadores de comparação.

O [referência de biblioteca de tempo de execução](../c-runtime-library/c-run-time-library-reference.md) define versões portáveis de todas as suas funções de manipulação de cadeia de caracteres. Para obter mais informações, consulte a categoria [internacionalização](../c-runtime-library/internationalization.md).

## <a name="mfc-support-for-mbcs-strings"></a>Suporte para cadeias de caracteres MBCS do MFC

A biblioteca de classes também está habilitada para conjuntos de caracteres multibyte, mas somente para caracteres de byte duplo (DBCS) de define.

Em um conjunto de caracteres multibyte, um caractere pode ser um ou dois bytes de largura. Se for ampla de dois bytes, o primeiro byte é um "byte inicial" especial que é escolhida de um intervalo específico, dependendo de qual código de página está em uso. Juntos, o cliente potencial e "rastros bytes" especificam uma codificação de caracteres exclusivo.

Se o MBCS símbolo é definido para uma compilação do seu programa, digite TCHAR, no qual `CString` baseia-se, é mapeado para **char**. Cabe a você para determinar quais bytes em um `CString` são bytes iniciais e quais são os bytes finais. A biblioteca de tempo de execução C fornece funções para ajudar você a determinar isso.

Em DBCS, uma determinada cadeia de caracteres pode conter todos os caracteres de ANSI de byte único, todos os caracteres de byte duplo ou uma combinação dos dois. Essas possibilidades requerem cuidado especial na análise de cadeias de caracteres. Isso inclui `CString` objetos.

> [!NOTE]
> Serialização de cadeia de caracteres Unicode em MFC pode ler cadeias de caracteres Unicode e MBCS, independentemente de qual versão do aplicativo que você está executando. Os arquivos de dados são portáteis entre as versões Unicode e MBCS do seu programa.

`CString` funções de membro usam versões especiais de "texto genérico" das funções de tempo de execução C, que eles chamam ou usar funções com suporte a Unicode. Portanto, por exemplo, se um `CString` função normalmente chamaria `strcmp`, ele chama a função de texto genérico correspondente `_tcscmp` em vez disso. Dependendo de como o Unicode e MBCS de símbolos são definidas, `_tcscmp` mapeia da seguinte maneira:

|||
|-|-|
|_MBCS definido|`_mbscmp`|
|_UNICODE definido|`wcscmp`|
|Nenhum símbolo definido|`strcmp`|

> [!NOTE]
> O Unicode e MBCS de símbolos são mutuamente exclusivos.

Mapeamentos de função de texto genérico para todas as rotinas de manipulação de cadeia de caracteres de tempo de execução são discutidos [referência de biblioteca de tempo de execução C](../c-runtime-library/c-run-time-library-reference.md). Para obter uma lista, consulte [internacionalização](../c-runtime-library/internationalization.md).

Da mesma forma, `CString` métodos são implementados usando mapeamentos de tipo de dados genéricos. Para habilitar o MBCS e Unicode, o MFC usa TCHAR para **char** ou `wchar_t`, LPTSTR para **char\***  ou `wchar_t*`e LPCTSTR para **char const\***  ou `const wchar_t*`. Eles garantem os mapeamentos corretos para MBCS ou Unicode.

## <a name="see-also"></a>Consulte também

[Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)  
[Manipulação de cadeias de caracteres](../c-runtime-library/string-manipulation-crt.md)  
