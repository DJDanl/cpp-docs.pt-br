---
title: "Usando CString | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CString (Visual C++)"
  - "Objetos de CString, Manipulação de cadeia de caracteres C++"
  - "Objetos de CString, contagem de referência"
ms.assetid: ed018aaf-8b10-46f9-828c-f9c092dc7609
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando CString
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os tópicos desta seção descrevem como programar com `CString`.  Para obter documentação de referência sobre a classe `CString`, consulte a documentação do [CStringT](../atl-mfc-shared/reference/cstringt-class.md).  
  
 Para usar `CString`, inclua o cabeçalho `atlstr.h`.  
  
 As classes `CString`, `CStringA` e `CStringW` são especializações de um modelo de classe chamado [CStringT](../atl-mfc-shared/reference/cstringt-class.md) com base no tipo de dados de caracteres compatíveis.  
  
 Um objeto `CStringW` contém o tipo `wchar_t` e oferece suporte a cadeias de caracteres Unicode.  Um objeto `CStringA` contém o tipo `char` e oferece suporte a cadeias de caracteres de byte único e de vários bytes \(MBCS\).  Um objeto `CString` é compatível com o tipo `char` ou o tipo `wchar_t`, dependendo se o símbolo `MBCS` ou o símbolo `UNICODE` for definido no momento da compilação.  
  
 Um objeto `CString` mantém os dados de caracteres em um objeto `CStringData`.  `CString` aceita cadeias de caracteres do estilo C de terminação `null`, mas não retém o caractere `null` nos dados de caracteres armazenados.  Em vez disso, `CString` rastreia o comprimento da cadeia de caracteres.  `CString` fornece uma terminação nula quando exporta uma cadeia de caracteres do estilo C.  Você pode inserir um `null` em uma `CString`, mas isso pode produzir resultados inesperados.  
  
 O conjunto de classes de cadeias de caracteres a seguir pode ser usado sem vincular uma biblioteca MFC, com ou sem suporte para CRT: `CAtlString`, `CAtlStringA` e `CAtlStringW`.  
  
 `CString` é usado em projetos nativos.  Para projetos de código gerenciado \(C\+\+\/CLI\), use `System::String`.  
  
 Para adicionar mais recursos que `CString`, `CStringA` ou `CStringW` oferecem no momento, você deve criar uma subclasse de `CStringT` que contém os recursos adicionais.  
  
 O código a seguir mostra como criar uma `CString` e imprimi\-la na saída padrão:  
  
```cpp  
#include <atlstr.h>  
  
int main() {  
    CString aCString = CString(_T("A string"));  
    _tprintf(_T("%s"), (LPCTSTR) aCString);  
}  
```  
  
## Nesta seção  
 [Operações CString básicas](../atl-mfc-shared/basic-cstring-operations.md)  
 Descreve as operações `CString` básicas, incluindo a criação de objetos de cadeias de caracteres literais de C, acessando caracteres individuais em uma `CString`, concatenando dois objetos e comparando objetos `CString`.  
  
 [Gerenciamento de dados da cadeia de caracteres](../atl-mfc-shared/string-data-management.md)  
 Discute o uso de Unicode e MBCS com `CString`.  
  
 [Semântica de CString](../atl-mfc-shared/cstring-semantics.md)  
 Explica como os objetos `CString` são usados.  
  
 [Operações CString relacionadas a cadeias de caracteres de estilo C](../atl-mfc-shared/cstring-operations-relating-to-c-style-strings.md)  
 Descreve a manipulação do conteúdo de um objeto `CString` como uma cadeia de caracteres de terminação nula de estilo C.  
  
 [Alocando e liberando memória para um BSTR](../atl-mfc-shared/allocating-and-releasing-memory-for-a-bstr.md)  
 Discute o uso de memória para um `BSTR` e objetos COM.  
  
 [Limpeza de exceção de CString](../atl-mfc-shared/cstring-exception-cleanup.md)  
 Explica que a limpeza explícita no MFC 3.0 e versões posteriores não é mais necessária.  
  
 [Passagem de argumento CString](../atl-mfc-shared/cstring-argument-passing.md)  
 Explica como passar objetos CString para funções e como retornar objetos `CString` de funções.  
  
 [Suporte a Unicode e Multibyte Character Set \(MBCS\)](../atl-mfc-shared/unicode-and-multibyte-character-set-mbcs-support.md)  
 Discute como o MFC é habilitado para suporte a Unicode e MBCS.  
  
## Referência  
 [CStringT](../atl-mfc-shared/reference/cstringt-class.md)  
 Fornece informações de referência sobre a classe `CStringT`.  
  
 [Classe de CSimpleStringT](../atl-mfc-shared/reference/csimplestringt-class.md)  
 Fornece informações de referência sobre a classe `CSimpleStringT`.  
  
## Seções relacionadas  
 [Cadeias de caracteres](../atl-mfc-shared/strings-atl-mfc.md)  
 Contem links para tópicos que descrevem várias maneiras de gerenciar dados da cadeia de caracteres.  
  
 [Instanciação do modelo de classe](../Topic/Class%20Template%20Instantiation.md)  
 `CString` é uma `typedef` com base na `CStringT`, uma instância de uma especialização de um modelo de classe.