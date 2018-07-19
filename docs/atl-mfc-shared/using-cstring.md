---
title: Usando CString | Microsoft Docs
ms.custom: ''
ms.date: 06/18/2018
ms.technology:
- cpp-mfc
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- CString objects, C++ string manipulation
- CString objects, reference counting
- CString class (Visual C++)
ms.assetid: ed018aaf-8b10-46f9-828c-f9c092dc7609
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 92807995183d2e5a34391250b36129e9bea01d66
ms.sourcegitcommit: 76fd30ff3e0352e2206460503b61f45897e60e4f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/13/2018
ms.locfileid: "39025838"
---
# <a name="using-cstring"></a>Usando CString
Os tópicos desta seção descrevem como programar com `CString`. Para obter a documentação de referência sobre as `CString` classe, consulte a documentação do [CStringT](../atl-mfc-shared/reference/cstringt-class.md).  
  
 Para usar `CString`, inclua o cabeçalho `atlstr.h`.  
  
 O `CString`, `CStringA`, e `CStringW` classes são especializações de um modelo de classe chamado [CStringT](../atl-mfc-shared/reference/cstringt-class.md) com base no tipo de dados de caractere, dar suporte a eles.  
  
 Um `CStringW` objeto contém o **wchar_t** digite e dá suporte a cadeias de caracteres Unicode. Um `CStringA` objeto contém o **char** tipo e dá suporte a byte único e multibyte (MBCS) cadeias de caracteres. Um `CString` objeto oferecer suporte a **char** tipo ou o `wchar_t` tipo, dependendo se o símbolo MBCS ou símbolo UNICODE é definido em tempo de compilação.  
  
 Um objeto `CString` mantém os dados de caracteres em um objeto `CStringData`. `CString` aceita cadeias de caracteres de estilo C terminada em nulo. `CString` Controla a cadeia de caracteres de comprimento para um desempenho mais rápido, mas também retém o caractere nulo nos dados de caractere armazenado para dar suporte à conversão em LPCWSTR. `CString` inclui o terminador nulo quando exporta uma cadeia de caracteres de estilo C. Você pode inserir um valor nulo em outros locais em um `CString`, mas isso pode produzir resultados inesperados.  
  
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
 [Operações básicas de CString](../atl-mfc-shared/basic-cstring-operations.md)  
 Descreve as operações `CString` básicas, incluindo a criação de objetos de cadeias de caracteres literais de C, acessando caracteres individuais em uma `CString`, concatenando dois objetos e comparando objetos `CString`.  
  
 [Gerenciamento de dados de cadeia de caracteres](../atl-mfc-shared/string-data-management.md)  
 Discute o uso de Unicode e MBCS com `CString`.  
  
 [Semântica de CString](../atl-mfc-shared/cstring-semantics.md)  
 Explica como os objetos `CString` são usados.  
  
 [Operações de CString relacionadas a cadeias de caracteres de estilo C](../atl-mfc-shared/cstring-operations-relating-to-c-style-strings.md)  
 Descreve a manipulação do conteúdo de um objeto `CString` como uma cadeia de caracteres de terminação nula de estilo C.  
  
 [Alocando e liberando memória para um BSTR](../atl-mfc-shared/allocating-and-releasing-memory-for-a-bstr.md)  
 Discute o uso de memória para um BSTR e objetos COM.  
  
 [Limpeza de exceção de CString](../atl-mfc-shared/cstring-exception-cleanup.md)  
 Explica que a limpeza explícita no MFC 3.0 e versões posteriores não é mais necessária.  
  
 [Passagem de argumento de CString](../atl-mfc-shared/cstring-argument-passing.md)  
 Explica como passar objetos CString para funções e como retornar objetos `CString` de funções.  
  
 [Suporte a MBCS (conjunto de caracteres multibyte) e Unicode](../atl-mfc-shared/unicode-and-multibyte-character-set-mbcs-support.md)  
 Discute como o MFC é habilitado para suporte a Unicode e MBCS.  
  
## <a name="reference"></a>Referência  
 [CStringT](../atl-mfc-shared/reference/cstringt-class.md)  
 Fornece informações de referência sobre a classe `CStringT`.  
  
 [Classe de CSimpleStringT](../atl-mfc-shared/reference/csimplestringt-class.md)  
 Fornece informações de referência sobre a classe `CSimpleStringT`.  
  
## <a name="related-sections"></a>Seções relacionadas  
 [Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)  
 Contem links para tópicos que descrevem várias maneiras de gerenciar dados da cadeia de caracteres.  
  
 [Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)

