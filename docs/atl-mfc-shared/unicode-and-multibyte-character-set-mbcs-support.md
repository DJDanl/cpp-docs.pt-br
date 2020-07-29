---
title: Suporte a Unicode e Multibyte Character Set (MBCS)
ms.date: 01/09/2017
helpviewer_keywords:
- MFC [C++], character set support
- MBCS [C++], strings and MFC support
- strings [C++], MBCS support in MFC
- character sets [C++], multibyte
- Unicode [C++], MFC strings
- Unicode [C++], string objects
- strings [C++], Unicode
- strings [C++], character set support
ms.openlocfilehash: 217690e09ed595bb9fa9572693bf774259c42412
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219021"
---
# <a name="unicode-and-multibyte-character-set-mbcs-support"></a>Suporte a Unicode e Multibyte Character Set (MBCS)

Alguns idiomas, por exemplo, japonês e chinês, têm grandes conjuntos de caracteres. Para dar suporte à programação para esses mercados, a biblioteca MFC (MFC) permite duas abordagens diferentes para lidar com conjuntos de caracteres grandes:

- [Unicode](#mfc-support-for-unicode-strings), **`wchar_t`** caracteres largos e cadeias com base codificados como UTF-16.

- [MBCS (conjuntos de caracteres multibyte)](#mfc-support-for-mbcs-strings), **`char`** com base em caracteres únicos ou duplos de byte e cadeias codificados em um conjunto de caracteres específico à localidade.

A Microsoft recomenda as bibliotecas de MFC Unicode para todo o novo desenvolvimento, e as bibliotecas MBCS foram preteridas no Visual Studio 2013 e no Visual Studio 2015. Esse não é mais o caso. Os avisos de substituição de MBCS foram removidos do Visual Studio 2017.

## <a name="mfc-support-for-unicode-strings"></a>Suporte do MFC para cadeias de caracteres Unicode

Toda a biblioteca de classes do MFC está condicionalmente habilitada para caracteres Unicode e cadeias de caracteres armazenados na largura de caractere como UTF-16. Em particular, a classe [CString](../atl-mfc-shared/reference/cstringt-class.md) é habilitada para Unicode.

Esses arquivos de biblioteca, depurador e DLL são usados para dar suporte ao Unicode no MFC:

|||||
|-|-|-|-|
|UAFXCW. LIB|UAFXCW. PDB|UAFXCWD. LIB|UAFXCWD. PDB|
|*Versão*do MFC U. lib|*Versão*do MFC U. pdb|U.DLL de*versão* do MFC|MFC*versão*UD. LIB|
|MFC*versão*UD. PDB|UD.DLL de*versão* do MFC|MFCS*versão*U. lib|MFCS*versão*U. pdb|
|MFCS*versão*UD. LIB|MFCS*versão*UD. PDB|MFCM*versão*U. lib|MFCM*versão*U. pdb|
|U.DLL*versão* do MFCM|MFCM*versão*UD. LIB|MFCM*versão*UD. PDB|UD.DLL*versão* do MFCM|

(a*versão* representa o número de versão do arquivo; por exemplo, ' 140 ' significa a versão 14,0.)

`CString`baseia-se no tipo de dados TCHAR. Se o símbolo _UNICODE for definido para uma compilação do seu programa, TCHAR será definido como tipo **`wchar_t`** , um tipo de codificação de caractere de 16 bits. Caso contrário, TCHAR será definido como **`char`** , a codificação normal de caracteres de 8 bits. Portanto, em Unicode, um `CString` é composto de caracteres de 16 bits. Sem o Unicode, ele é composto por caracteres do tipo **`char`** .

Para concluir a programação Unicode do seu aplicativo, você também deve:

- Use a macro _T para codificar condicionalmente cadeias de caracteres literais para serem portáveis para Unicode.

- Quando você passa cadeias de caracteres, preste atenção para se os argumentos da função exigem um comprimento ou um comprimento em bytes. A diferença é importante se você estiver usando cadeias de caracteres Unicode.

- Use versões portáteis das funções de manipulação de cadeia de caracteres de tempo de execução C.

- Use os seguintes tipos de dados para caracteres e ponteiros de caractere:

  - Use TCHAR para usar **`char`** .

  - Use LPTSTR Onde você usaria **`char`** <strong>\*</strong> .

  - Use LPCTSTR em que você usaria **Char const** <strong>\*</strong> . `CString`fornece o operador LPCTSTR para converter entre `CString` e LPCTSTR.

`CString`também fornece construtores com reconhecimento de Unicode, operadores de atribuição e operadores de comparação.

A [referência da biblioteca de tempo de execução](../c-runtime-library/c-run-time-library-reference.md) define versões portáteis de todas as suas funções de manipulação de cadeia de caracteres. Para obter mais informações, consulte a [internacionalização](../c-runtime-library/internationalization.md)de categoria.

## <a name="mfc-support-for-mbcs-strings"></a>Suporte do MFC para cadeias de caracteres MBCS

A biblioteca de classes também é habilitada para conjuntos de caracteres multibyte, mas apenas para DBCS (conjuntos de caracteres de dois bytes).

Em um conjunto de caracteres multibyte, um caractere pode ter um ou dois bytes de largura. Se tiver dois bytes de largura, seu primeiro byte será um "byte de Lead" especial que é escolhido de um intervalo específico, dependendo de qual página de código está em uso. Em conjunto, o cliente potencial e "bytes de trilha" especificam uma codificação de caracteres exclusiva.

Se o símbolo _MBCS for definido para uma compilação de seu programa, digite TCHAR, no qual `CString` é baseado, é mapeado para **`char`** . Cabe a você determinar quais bytes em um `CString` são bytes de Lead e quais são os bytes de trilha. A biblioteca de tempo de execução do C fornece funções para ajudá-lo a determinar isso.

Em DBCS, uma determinada cadeia de caracteres pode conter todos os caracteres ANSI de byte único, todos os caracteres de byte duplo ou uma combinação dos dois. Essas possibilidades exigem cuidados especiais na análise de cadeias de caracteres. Isso inclui `CString` objetos.

> [!NOTE]
> A serialização de cadeia de caracteres Unicode no MFC pode ler cadeias Unicode e MBCS, independentemente da versão do aplicativo que você está executando. Seus arquivos de dados são portáteis entre as versões Unicode e MBCS do seu programa.

`CString`as funções de membro usam versões especiais de "texto genérico" das funções de tempo de execução C que chamam, ou usam funções que reconhecem Unicode. Portanto, por exemplo, se uma `CString` função normalmente chamar `strcmp` , ele chamará a função de texto genérico correspondente `_tcscmp` em vez disso. Dependendo de como os símbolos _MBCS e _UNICODE são definidos, `_tcscmp` o mapeia da seguinte maneira:

|||
|-|-|
|_MBCS definido|`_mbscmp`|
|_UNICODE definido|`wcscmp`|
|Nenhum símbolo definido|`strcmp`|

> [!NOTE]
> Os símbolos _MBCS e _UNICODE são mutuamente exclusivos.

Os mapeamentos de função de texto genérico para todas as rotinas de manipulação de cadeia de caracteres de tempo de execução são discutidos em [referência de biblioteca de tempo de execução em C](../c-runtime-library/c-run-time-library-reference.md). Para obter uma lista, consulte [internacionalização](../c-runtime-library/internationalization.md).

Da mesma forma, os `CString` métodos são implementados usando mapeamentos de tipo de dados genéricos. Para habilitar MBCS e Unicode, o MFC usa TCHAR para **`char`** ou **`wchar_t`** , LPTStr para **`char`** <strong>\*</strong> or `wchar_t*` e LPCTSTR para **const char** <strong>\*</strong> ou `const wchar_t*` . Eles garantem os mapeamentos corretos para o MBCS ou o Unicode.

## <a name="see-also"></a>Confira também

[Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)<br/>
[Manipulação de cadeia de caracteres](../c-runtime-library/string-manipulation-crt.md)
