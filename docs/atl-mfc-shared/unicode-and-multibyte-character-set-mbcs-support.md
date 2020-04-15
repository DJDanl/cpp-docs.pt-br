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
ms.openlocfilehash: e1b93a3540cba553afd8f133c18496bddbd561b8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317431"
---
# <a name="unicode-and-multibyte-character-set-mbcs-support"></a>Suporte a Unicode e Multibyte Character Set (MBCS)

Algumas línguas, por exemplo, japonesas e chinesas, têm grandes conjuntos de caracteres. Para suportar a programação para esses mercados, o Microsoft Foundation Class Library (MFC) permite duas abordagens diferentes para lidar com grandes conjuntos de caracteres:

- [Unicode](#mfc-support-for-unicode-strings) `wchar_t` , com base em caracteres largos e strings codificados como UTF-16.

- [Conjuntos de caracteres multibytes (MBCS)](#mfc-support-for-mbcs-strings), caracteres e strings baseados em **caracteres** de um ou dois bytes baseados em char codificados em um conjunto de caracteres específicos do local.

A Microsoft recomendou as bibliotecas MFC Unicode para todos os novos desenvolvimentos, e as bibliotecas MBCS foram preteridas no Visual Studio 2013 e visual studio 2015. Esse não é mais o caso. Os avisos de depreciação do MBCS foram removidos no Visual Studio 2017.

## <a name="mfc-support-for-unicode-strings"></a>Suporte mfc para strings Unicode

Toda a biblioteca de classes Do MFC está habilitada condicionalmente para caracteres Unicode e strings armazenados em caracteres largos como UTF-16. Em particular, a classe [CString](../atl-mfc-shared/reference/cstringt-class.md) é habilitada para Unicode.

Esses arquivos de biblioteca, depurador e DLL são usados para suportar unicode em MFC:

|||||
|-|-|-|-|
|UAFXCW. Lib|UAFXCW. Pdb|UAFXCWD. Lib|UAFXCWD. Pdb|
|MFC*versão*U.LIB|MFC*versão*U.PDB|MFC*versão*U.DLL|Versão*MFC*UD. Lib|
|Versão*MFC*UD. Pdb|Versão*MFC*UD. Dll|MFCS*versão*U.LIB|MFCS*versão*U.PDB|
|MFCS*versão*UD. Lib|MFCS*versão*UD. Pdb|MFCM*versão*U.LIB|MFCM*versão*U.PDB|
|MFCM*versão*U.DLL|Versão*MFCM*UD. Lib|Versão*MFCM*UD. Pdb|Versão*MFCM*UD. Dll|

*(versão* representa o número da versão do arquivo; por exemplo, '140' significa versão 14.0.)

`CString`é baseado no tipo de dados TCHAR. Se o símbolo _UNICODE for definido para uma compilação `wchar_t`do seu programa, o TCHAR será definido como tipo , um tipo de codificação de caracteres de 16 bits. Caso contrário, TCHAR é definido como **char**, a codificação normal de caracteres de 8 bits. Portanto, sob Unicode, `CString` a é composta de caracteres de 16 bits. Sem unicode, ele é composto de caracteres de tipo **char**.

Para completar a programação Unicode da sua aplicação, você também deve:

- Use o _T macro para codificar condicionalmente as strings literais para serem portáteis para unicode.

- Quando você passar as strings, preste atenção se os argumentos de função requerem um comprimento nos caracteres ou um comprimento em bytes. A diferença é importante se você estiver usando strings Unicode.

- Use versões portáteis das funções de manuseio de strings em tempo de execução C.

- Use os seguintes tipos de dados para caracteres e ponteiros de caracteres:

  - Use TCHAR onde você usaria **char**.

  - Use LPTSTR onde você usaria **char**<strong>\*</strong>.

  - Use LPCTSTR onde você usaria **const char**<strong>\*</strong>. `CString`fornece ao operador LPCTSTR `CString` para converter entre e LPCTSTR.

`CString`também fornece construtores, operadores de atribuição e operadores de comparação com reconhecimento unicode.

A [referência de biblioteca em tempo de execução](../c-runtime-library/c-run-time-library-reference.md) define versões portáteis de todas as suas funções de manuseio de strings. Para obter mais informações, consulte a categoria [Internacionalização](../c-runtime-library/internationalization.md).

## <a name="mfc-support-for-mbcs-strings"></a>Suporte MFC para strings MBCS

A biblioteca de classes também está habilitada para conjuntos de caracteres multibytes, mas apenas para conjuntos de caracteres de byte duplo (DBCS).

Em um conjunto de caracteres multibytes, um personagem pode ter um ou dois bytes de largura. Se for de dois bytes de largura, seu primeiro byte é um "byte de chumbo" especial que é escolhido a partir de uma determinada gama, dependendo de qual página de código está em uso. Juntos, o lead e o "trail bytes" especificam uma codificação de caracteres única.

Se o símbolo _MBCS for definido para uma compilação `CString` do seu programa, digite TCHAR, no qual se baseia, mapas para **char**. Cabe a você determinar quais bytes `CString` em um são bytes de chumbo e quais são bytes de trilha. A biblioteca c de tempo de execução fornece funções para ajudá-lo a determinar isso.

Em DBCS, uma seqüência dada pode conter todos os caracteres ANSI de byte único, todos os caracteres de byte duplo ou uma combinação dos dois. Essas possibilidades requerem cuidados especiais nas cordas de análise. Isso inclui `CString` objetos.

> [!NOTE]
> A serialização de seqüência de strings unicode no MFC pode ler as seqüências Unicode e MBCS, independentemente de qual versão do aplicativo você está executando. Seus arquivos de dados são portáteis entre as versões Unicode e MBCS do seu programa.

`CString`as funções de membro usam versões especiais de "texto genérico" das funções de tempo de execução C que eles chamam, ou usam funções com reconhecimento unicode. Portanto, por exemplo, `CString` se uma função `strcmp`normalmente chamaria, ela `_tcscmp` chama a função de texto genérico correspondente em vez disso. Dependendo de como os símbolos _MBCS `_tcscmp` e _UNICODE são definidos, mapeia da seguinte forma:

|||
|-|-|
|_MBCS definido|`_mbscmp`|
|_UNICODE definido|`wcscmp`|
|Nenhum dos símbolos definidos|`strcmp`|

> [!NOTE]
> Os símbolos _MBCS e _UNICODE são mutuamente exclusivos.

Os mapeamentos de funções de texto genérico para todas as rotinas de manipulação de strings em tempo de execução são discutidos no [C Run-Time Library Reference](../c-runtime-library/c-run-time-library-reference.md). Para obter uma lista, consulte [Internacionalização](../c-runtime-library/internationalization.md).

Da mesma `CString` forma, os métodos são implementados usando mapeamentos genéricos do tipo de dados. Para habilitar tanto o MBCS quanto o Unicode, o MFC `wchar_t*`usa o TCHAR para **char** ou `wchar_t`, LPTSTR para **char** <strong>\*</strong> ou , e LPCTSTR para **const char** <strong>\*</strong> ou `const wchar_t*`. Estes garantem os mapeamentos corretos para MBCS ou Unicode.

## <a name="see-also"></a>Confira também

[Cordas (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)<br/>
[Manipulação de cordas](../c-runtime-library/string-manipulation-crt.md)
