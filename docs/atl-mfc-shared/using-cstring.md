---
title: Usando CString
ms.date: 06/18/2018
helpviewer_keywords:
- CString objects, C++ string manipulation
- CString objects, reference counting
- CString class (Visual C++)
ms.assetid: ed018aaf-8b10-46f9-828c-f9c092dc7609
ms.openlocfilehash: 8ebf3441c7d8856fe412e2efed4c717b01ced362
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219008"
---
# <a name="using-cstring"></a>Usando CString

Os tópicos desta seção descrevem como programar com `CString`. Para obter a documentação de referência sobre a `CString` classe, consulte a documentação de [CStringT](../atl-mfc-shared/reference/cstringt-class.md).

Para usar `CString`, inclua o cabeçalho `atlstr.h`.

As `CString` `CStringA` classes, e `CStringW` são especializações de um modelo de classe chamado [CStringT](../atl-mfc-shared/reference/cstringt-class.md) com base no tipo de dados de caractere que eles dão suporte.

Um `CStringW` objeto contém o **`wchar_t`** tipo e oferece suporte a cadeias de caracteres Unicode. Um `CStringA` objeto contém o **`char`** tipo e dá suporte a cadeias de caracteres de byte único e multi-byte (MBCS). Um `CString` objeto dá suporte ao **`char`** tipo ou ao **`wchar_t`** tipo, dependendo se o símbolo MBCS ou o símbolo Unicode está definido no momento da compilação.

Um objeto `CString` mantém os dados de caracteres em um objeto `CStringData`. `CString`aceita cadeias de caracteres em estilo C terminadas em nulo. `CString`controla o tamanho da cadeia de caracteres para um desempenho mais rápido, mas também retém o caractere nulo nos dados de caracteres armazenados para dar suporte à conversão em LPCWSTR. `CString`inclui o terminador nulo quando exporta uma cadeia de caracteres em estilo C. Você pode inserir um valor nulo em outros locais em um `CString` , mas ele pode produzir resultados inesperados.

O conjunto de classes de cadeias de caracteres a seguir pode ser usado sem vincular uma biblioteca MFC, com ou sem suporte para CRT: `CAtlString`, `CAtlStringA` e `CAtlStringW`.

`CString` é usado em projetos nativos. Para projetos de código gerenciado (C++/CLI), use `System::String`.

Para adicionar mais recursos que `CString`, `CStringA` ou `CStringW` oferecem no momento, você deve criar uma subclasse de `CStringT` que contém os recursos adicionais.

O código a seguir mostra como criar uma `CString` e imprimi-la na saída padrão:

```cpp
#include <atlstr.h>

int main() {
    CString aCString = CString(_T("A string"));
    _tprintf(_T("%s"), (LPCTSTR) aCString);
}
```

## <a name="in-this-section"></a>Nesta seção

[Operações de CString básicas](../atl-mfc-shared/basic-cstring-operations.md)<br/>
Descreve as operações `CString` básicas, incluindo a criação de objetos de cadeias de caracteres literais de C, acessando caracteres individuais em uma `CString`, concatenando dois objetos e comparando objetos `CString`.

[Cadeia de caracteres Gerenciamento de Dados](../atl-mfc-shared/string-data-management.md)<br/>
Discute o uso de Unicode e MBCS com `CString`.

[Semântica de CString](../atl-mfc-shared/cstring-semantics.md)<br/>
Explica como os objetos `CString` são usados.

[Operações CString relacionadas a cadeias de estilo C](../atl-mfc-shared/cstring-operations-relating-to-c-style-strings.md)<br/>
Descreve a manipulação do conteúdo de um objeto `CString` como uma cadeia de caracteres de terminação nula de estilo C.

[Alocando e liberando memória para um BSTR](../atl-mfc-shared/allocating-and-releasing-memory-for-a-bstr.md)<br/>
Discute o uso de memória para um BSTR e objetos COM.

[Limpeza de exceção CString](../atl-mfc-shared/cstring-exception-cleanup.md)<br/>
Explica que a limpeza explícita no MFC 3.0 e versões posteriores não é mais necessária.

[Passagem de argumento CString](../atl-mfc-shared/cstring-argument-passing.md)<br/>
Explica como passar objetos CString para funções e como retornar objetos `CString` de funções.

[Suporte a MBCS (conjunto de caracteres multibyte) e Unicode](../atl-mfc-shared/unicode-and-multibyte-character-set-mbcs-support.md)<br/>
Discute como o MFC é habilitado para suporte a Unicode e MBCS.

## <a name="reference"></a>Referência

[CStringT](../atl-mfc-shared/reference/cstringt-class.md)<br/>
Fornece informações de referência sobre a classe `CStringT`.

[Classe CSimpleStringT](../atl-mfc-shared/reference/csimplestringt-class.md)<br/>
Fornece informações de referência sobre a classe `CSimpleStringT`.

## <a name="related-sections"></a>Seções relacionadas

[Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)<br/>
Contem links para tópicos que descrevem várias maneiras de gerenciar dados da cadeia de caracteres.

[Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)
