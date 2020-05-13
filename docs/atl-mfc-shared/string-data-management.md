---
title: Gerenciamento de dados da cadeia de caracteres
ms.date: 11/04/2016
helpviewer_keywords:
- Unicode, string objects
ms.assetid: 0b53a542-eeb1-4108-9ada-6700645b6f8f
ms.openlocfilehash: 7f92b38ac659faef2dd9319b2f204ba837f0d473
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317457"
---
# <a name="string-data-management"></a>Gerenciamento de dados da cadeia de caracteres

O Visual C++ fornece várias maneiras de gerenciar dados de string:

- [Manipulação de cordas](../c-runtime-library/string-manipulation-crt.md) para trabalhar com strings nulamente estilo C

- Funções da API do Win32 para gerenciamento de strings

- [Classe CStringT](../atl-mfc-shared/reference/cstringt-class.md)classe MFC, que fornece objetos de corda flexíveis e resizáveis

- Classe [CStringT Class](../atl-mfc-shared/reference/cstringt-class.md), que fornece um objeto de string independente de MFC com a mesma funcionalidade que`CString`

Quase todos os programas funcionam com dados de strings. A classe `CString` da MFC é muitas vezes a melhor solução para o manuseio flexível de cordas. A partir da versão `CString` 7.0, pode ser usado em programas mfc ou independentes de MFC. Tanto a biblioteca de `CString` tempo de execução quanto as strings de suporte contendo caracteres multibyte (wide), como na programação Unicode ou MBCS.

Este artigo descreve os serviços de uso geral que a biblioteca de classe fornece relacionados à manipulação de strings. Os tópicos abordados neste artigo incluem:

- [Unicode e MBCS fornecem portabilidade](#_core_unicode_and_mbcs_provide_portability)

- [CStrings e ponteiros de char const](#_core_cstrings_and_const_char_pointers)

- [Contagem de referência de cstring](#_core_cstring_reference_counting)

A classe [CStringT](../atl-mfc-shared/reference/cstringt-class.md) fornece suporte para manipular strings. Destina-se a substituir e estender a funcionalidade normalmente fornecida pelo pacote de string de biblioteca de tempo de execução C. A `CString` classe fornece funções de membros e operadores para manuseio simplificado de cordas, semelhantes às encontradas no Basic. A classe também fornece construtores e operadores para construir, `CString`atribuir e comparar os tipos de dados de cadeia C++. Como `CString` não é `CObject`derivado, você `CString` pode usar objetos independentemente da maioria da Microsoft Foundation Class Library (MFC).

`CString`objetos seguem "semântica de valor". Um `CString` objeto representa um valor único. Pense em `CString` uma string real, não como um ponteiro para uma corda.

Um `CString` objeto representa uma seqüência de um número variável de caracteres. `CString`objetos podem ser pensados como matrizes de caracteres.

## <a name="unicode-and-mbcs-provide-portability"></a><a name="_core_unicode_and_mbcs_provide_portability"></a>Unicode e MBCS fornecem portabilidade

Com a versão 3.0 do MFC `CString`e posterior, o MFC, incluindo , está habilitado para conjuntos de caracteres Unicode e multibytes (MBCS). Esse suporte torna mais fácil para você escrever aplicativos portáteis que você pode construir para caracteres Unicode ou ANSI. Para habilitar essa portabilidade, `CString` cada caractere em um objeto `wchar_t` é do tipo TCHAR, que é `char` definido como se você definisse o símbolo _UNICODE quando você constrói sua aplicação, ou como se não. Um `wchar_t` personagem tem 16 bits de largura. O MBCS é habilitado se você construir com o símbolo _MBCS definido. O próprio MFC é construído com o símbolo _MBCS (para as bibliotecas NAFX) ou o símbolo _UNICODE (para as bibliotecas UAFX) definido.

> [!NOTE]
> Os `CString` exemplos neste e os artigos que acompanham as strings mostram strings literais devidamente formatadas para portabilidade Unicode, usando a macro _T, que traduz a seqüência literal para a forma:

`L"literal string"`

> [!NOTE]
> que o compilador trata como uma seqüência unicode. Por exemplo, o código a seguir:

[!code-cpp[NVC_ATLMFC_Utilities#187](../atl-mfc-shared/codesnippet/cpp/string-data-management_1.cpp)]

> [!NOTE]
> é traduzido como uma seqüência unicode se _UNICODE for definida ou como uma seqüência DE string ANSI, se não. Para obter mais informações, consulte o artigo Suporte ao [Conjunto de Caracteres Unicode e Multibytes (MBCS).](../atl-mfc-shared/unicode-and-multibyte-character-set-mbcs-support.md)

Um `CString` objeto pode armazenar até INT_MAX (2.147.483.647) caracteres. O tipo de dados TCHAR é usado `CString` para obter ou definir caracteres individuais dentro de um objeto. Ao contrário dos `CString` arrays de caracteres, a classe tem um recurso de alocação de memória incorporado. Isso `CString` permite que os objetos cresçam automaticamente conforme necessário (ou `CString` seja, você não precisa se preocupar em cultivar um objeto para caber em strings mais longas).

## <a name="cstrings-and-const-char-pointers"></a><a name="_core_cstrings_and_const_char_pointers"></a>CStrings e ponteiros de char const

Um `CString` objeto também pode agir como uma `PCXSTR`seqüência literal estilo C (uma , que é o mesmo que **const char** <strong>\*</strong> se não sob Unicode). O operador de conversão [CSimpleStringT::operator PCXSTR](../atl-mfc-shared/reference/csimplestringt-class.md#operator_pcxstr) permite que `CString` objetos sejam substituídos livremente por ponteiros de caracteres em chamadas de função. O **construtor CString (LPCWSTR)** `pszSrc` **)** permite que ponteiros `CString` de caracteres sejam substituídos por objetos.

Nenhuma tentativa é `CString` feita para dobrar objetos. Se você `CString` fizer dois `Chicago`objetos contendo, `Chicago` por exemplo, os caracteres são armazenados em dois lugares. (Isso pode não ser verdade para versões futuras do MFC, então você não deve depender dele.)

> [!NOTE]
> Use as funções [csimplestringt::getBuffer](../atl-mfc-shared/reference/csimplestringt-class.md#getbuffer) e [CSimpleStringT::ReleaseBuffer](../atl-mfc-shared/reference/csimplestringt-class.md#releasebuffer) quando `CString` você precisa acessar diretamente um ponteiro não constante para um caractere.

> [!NOTE]
> Use as funções de membro [CStringT::AllocSysString](../atl-mfc-shared/reference/cstringt-class.md#allocsysstring) e [CStringT::SetSysString](../atl-mfc-shared/reference/cstringt-class.md#setsysstring) para alocar e definir objetos BSTR usados na Automação (anteriormente conhecido como Automação OLE).

> [!NOTE]
> Sempre que `CString` possível, aloque objetos no quadro em vez de no monte. Isso salva a memória e simplifica a passagem de parâmetros.

A `CString` classe não é implementada como uma classe `CString` de coleção da Microsoft Foundation Class Library, embora os objetos certamente possam ser armazenados como elementos em coleções.

## <a name="cstring-reference-counting"></a><a name="_core_cstring_reference_counting"></a>Contagem de referência de cstring

A partir da versão 4.0 do MFC, quando os objetos [da Classe CStringT](../atl-mfc-shared/reference/cstringt-class.md) são copiados, o MFC incrementa uma contagem de referência em vez de copiar os dados. Isso torna os parâmetros `CString` de passagem por valor e o retorno de objetos por valor mais eficientes. Essas operações fazem com que o construtor de cópias seja chamado, às vezes mais de uma vez. Incrementar uma contagem de referência reduz essa `CString` sobrecarga para essas operações comuns e torna o uso de uma opção mais atraente.

À medida que cada cópia é destruída, a contagem de referência no objeto original é decretada. O `CString` objeto original não é destruído até que sua contagem de referência seja reduzida a zero.

Você pode `CString` usar as funções de membro [CSimpleStringT::LockBuffer](../atl-mfc-shared/reference/csimplestringt-class.md#lockbuffer) e [CSimpleStringT::UnlockBuffer](../atl-mfc-shared/reference/csimplestringt-class.md#unlockbuffer) para desativar ou ativar a contagem de referências.

## <a name="see-also"></a>Confira também

[Tópicos MFC gerais](../mfc/general-mfc-topics.md)
