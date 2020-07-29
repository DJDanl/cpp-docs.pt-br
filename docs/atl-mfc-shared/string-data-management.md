---
title: Gerenciamento de dados da cadeia de caracteres
ms.date: 11/04/2016
helpviewer_keywords:
- Unicode, string objects
ms.assetid: 0b53a542-eeb1-4108-9ada-6700645b6f8f
ms.openlocfilehash: 2da8967effeb6ff439cf5b3cece31f63ee77a761
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219034"
---
# <a name="string-data-management"></a>Gerenciamento de dados da cadeia de caracteres

O Visual C++ fornece várias maneiras de gerenciar dados de cadeia de caracteres:

- [Manipulação de cadeia](../c-runtime-library/string-manipulation-crt.md) para trabalhar com cadeias de caracteres terminadas em nulo no estilo C

- Funções de API do Win32 para gerenciar cadeias de caracteres

- [Classe CStringT](../atl-mfc-shared/reference/cstringt-class.md)classe do MFC, que fornece objetos de cadeia de caracteres flexíveis e redimensionáveis

- Classe [CStringT](../atl-mfc-shared/reference/cstringt-class.md)Class, que fornece um objeto String independente de MFC com a mesma funcionalidade que`CString`

Quase todos os programas funcionam com dados de cadeia de caracteres. `CString`A classe do MFC é geralmente a melhor solução para manipulação de cadeia de caracteres flexível. A partir da versão 7,0, o `CString` pode ser usado em programas MFC ou independentes do MFC. A biblioteca de tempo de execução e as `CString` cadeias de caracteres de suporte que contêm um multibyte (largo), como na programação Unicode ou MBCS.

Este artigo descreve os serviços de uso geral que a biblioteca de classes fornece relacionado à manipulação de cadeias de caracteres. Os tópicos abordados neste artigo incluem:

- [Unicode e MBCS fornecem portabilidade](#_core_unicode_and_mbcs_provide_portability)

- [Indicadores e ponteiros de caracteres const](#_core_cstrings_and_const_char_pointers)

- [Contagem de referência de CString](#_core_cstring_reference_counting)

A classe de [classe CStringT](../atl-mfc-shared/reference/cstringt-class.md) fornece suporte para manipular cadeias de caracteres. Ele se destina a substituir e estender a funcionalidade normalmente fornecida pelo pacote de cadeia de caracteres de biblioteca de tempo de execução C. A `CString` classe fornece funções de membro e operadores para manipulação simplificada de cadeia de caracteres, semelhante àquelas encontradas em básico. A classe também fornece construtores e operadores para construir, atribuir e comparar `CString` s e tipos de dados de cadeia de caracteres C++ padrão. Como `CString` o não é derivado do `CObject` , você pode usar `CString` objetos independentemente da maioria das biblioteca MFC (MFC).

`CString`os objetos seguem "semântica de valor". Um `CString` objeto representa um valor exclusivo. Imagine como uma `CString` cadeia de caracteres real, não como um ponteiro para uma cadeia de caracteres.

Um `CString` objeto representa uma sequência de um número variável de caracteres. `CString`os objetos podem ser considerados como matrizes de caracteres.

## <a name="unicode-and-mbcs-provide-portability"></a><a name="_core_unicode_and_mbcs_provide_portability"></a>Unicode e MBCS fornecem portabilidade

Com o MFC versão 3,0 e posterior, o MFC, incluindo `CString` , é habilitado para os conjuntos de caracteres Unicode e multibyte (MBCS). Esse suporte torna mais fácil para você escrever aplicativos portáteis que podem ser criados para caracteres Unicode ou ANSI. Para habilitar essa portabilidade, cada caractere em um `CString` objeto é do tipo TCHAR, que é definido como **`wchar_t`** se você definir o símbolo _UNICODE ao compilar seu aplicativo ou como **`char`** se não fosse. Um **`wchar_t`** caractere tem 16 bits de largura. MBCS será habilitado se você criar com o símbolo _MBCS definido. O próprio MFC é criado com o símbolo de _MBCS (para as bibliotecas NAFX) ou o símbolo de _UNICODE (para as bibliotecas UAFX) definido.

> [!NOTE]
> Os `CString` exemplos neste e os artigos que o acompanham em cadeias de caracteres mostram cadeias de caracteres literais formatadas corretamente para portabilidade Unicode, usando a macro _T, que traduz a cadeia de caracteres literal para o formulário:

`L"literal string"`

> [!NOTE]
> que o compilador trata como uma cadeia de caracteres Unicode. Por exemplo, o código a seguir:

[!code-cpp[NVC_ATLMFC_Utilities#187](../atl-mfc-shared/codesnippet/cpp/string-data-management_1.cpp)]

> [!NOTE]
> é convertido como uma cadeia de caracteres Unicode se _UNICODE for definido ou como uma cadeia de caracteres ANSI, se não for. Para obter mais informações, consulte o artigo [suporte a Unicode e conjunto de caracteres multibyte (MBCS)](../atl-mfc-shared/unicode-and-multibyte-character-set-mbcs-support.md).

Um `CString` objeto pode armazenar até INT_MAX (2.147.483.647) caracteres. O tipo de dados TCHAR é usado para obter ou definir caracteres individuais dentro de um `CString` objeto. Ao contrário das matrizes de caracteres, a `CString` classe tem um recurso de alocação de memória interno. Isso permite que `CString` os objetos cresçam automaticamente conforme necessário (ou seja, você não precisa se preocupar em aumentar um `CString` objeto para caber em cadeias de caracteres mais longas).

## <a name="cstrings-and-const-char-pointers"></a><a name="_core_cstrings_and_const_char_pointers"></a>Indicadores e ponteiros de caracteres const

Um `CString` objeto também pode agir como uma cadeia de caracteres C-Style literal (um `PCXSTR` , que é o mesmo que **const char** , <strong>\*</strong> se não estiver em Unicode). O operador de conversão [CSimpleStringT:: Operator PCXSTR](../atl-mfc-shared/reference/csimplestringt-class.md#operator_pcxstr) permite que os `CString` objetos sejam substituídos livremente por ponteiros de caracteres em chamadas de função. O construtor **CString (LPCWSTR** `pszSrc` **)** permite que os ponteiros de caracteres sejam substituídos por `CString` objetos.

Nenhuma tentativa é feita para dobrar `CString` objetos. Se você fizer dois `CString` objetos que contenham `Chicago` , por exemplo, os caracteres em `Chicago` são armazenados em dois lugares. (Isso pode não ser verdadeiro para versões futuras do MFC, portanto, você não deve depender dela).

> [!NOTE]
> Use as funções de membro [CSimpleStringT:: GetBuffer](../atl-mfc-shared/reference/csimplestringt-class.md#getbuffer) e [CSimpleStringT:: ReleaseBuffer](../atl-mfc-shared/reference/csimplestringt-class.md#releasebuffer) quando você precisar acessar diretamente um `CString` como um ponteiro não constante para um caractere.

> [!NOTE]
> Use as funções de membro [CStringT:: AllocSysString](../atl-mfc-shared/reference/cstringt-class.md#allocsysstring) e [CStringT:: SetSysString](../atl-mfc-shared/reference/cstringt-class.md#setsysstring) para alocar e definir objetos BSTR usados na automação (anteriormente conhecido como automação OLE).

> [!NOTE]
> Sempre que possível, aloque `CString` objetos no quadro em vez de no heap. Isso economiza memória e simplifica a passagem de parâmetros.

A `CString` classe não é implementada como uma classe de coleção biblioteca MFC, embora os `CString` objetos certamente possam ser armazenados como elementos em coleções.

## <a name="cstring-reference-counting"></a><a name="_core_cstring_reference_counting"></a>Contagem de referência de CString

A partir da versão 4,0 do MFC, quando os objetos da [classe CStringT](../atl-mfc-shared/reference/cstringt-class.md) são copiados, o MFC incrementa uma contagem de referência em vez de copiar os dados. Isso torna a passagem de parâmetros por valor e o retorno `CString` de objetos por valor mais eficiente. Essas operações fazem com que o construtor de cópia seja chamado, às vezes mais de uma vez. Incrementar uma contagem de referência reduz essa sobrecarga para essas operações comuns e faz uso `CString` de uma opção mais atraente.

À medida que cada cópia é destruída, a contagem de referência no objeto original é decrementada. O `CString` objeto original não é destruído até que sua contagem de referência seja reduzida para zero.

Você pode usar as `CString` funções de membro [CSimpleStringT:: LockBuffer](../atl-mfc-shared/reference/csimplestringt-class.md#lockbuffer) e [CSimpleStringT:: UnlockBuffer](../atl-mfc-shared/reference/csimplestringt-class.md#unlockbuffer) para desabilitar ou habilitar a contagem de referência.

## <a name="see-also"></a>Confira também

[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)
