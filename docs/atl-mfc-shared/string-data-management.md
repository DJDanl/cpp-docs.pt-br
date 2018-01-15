---
title: Gerenciamento de dados de cadeia de caracteres | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs: C++
helpviewer_keywords: Unicode, string objects
ms.assetid: 0b53a542-eeb1-4108-9ada-6700645b6f8f
caps.latest.revision: "15"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ad7a17b1b34375fcb45019bcaf8878757288a290
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="string-data-management"></a>Gerenciamento de dados da cadeia de caracteres
O Visual C++ fornece várias maneiras para gerenciar dados de cadeia de caracteres:  
  
-   [Manipulação de cadeia de caracteres](../c-runtime-library/string-manipulation-crt.md) para trabalhar com cadeias de caracteres terminada em nulo do estilo C  
  
-   Funções de API do Win32 para gerenciar as cadeias de caracteres  
  
-   Classe do MFC [CStringT classe](../atl-mfc-shared/reference/cstringt-class.md), que fornece objetos de cadeia de caracteres flexível, redimensionável  
  
-   Classe [CStringT classe](../atl-mfc-shared/reference/cstringt-class.md), que fornece um objeto de cadeia de caracteres independente do MFC com a mesma funcionalidade`CString`  
  
 Quase todos os programas trabalham com dados de cadeia de caracteres. Do MFC `CString` classe geralmente é a melhor solução para manipulação de cadeia de caracteres flexível. Começando com a versão 7.0, `CString` pode ser usado em programas MFC ou independente do MFC. Os dois a biblioteca de tempo de execução e `CString` suporte a cadeias de caracteres que contém caracteres multibyte de (horizontal), como em programação Unicode ou MBCS.  
  
 Este artigo descreve os serviços de uso gerais que a biblioteca de classe fornece relacionados a manipulação de cadeia de caracteres. Os tópicos abordados neste artigo incluem:  
  
-   [Portabilidade de Unicode e MBCS fornecer](#_core_unicode_and_mbcs_provide_portability)  
  
-   [CStrings e ponteiros de char constantes](#_core_cstrings_and_const_char_pointers)  
  
-   [Contagem de referência de CString](#_core_cstring_reference_counting)  
  
 O [CStringT classe](../atl-mfc-shared/reference/cstringt-class.md) classe oferece suporte para manipulação de cadeias de caracteres. Destina-se a substituir e estender a funcionalidade que normalmente é fornecida pelo pacote de cadeia de caracteres de biblioteca de tempo de execução C. O `CString` classe fornece funções de membro e operadores para manipulação simplificada de cadeia de caracteres, semelhantes aos encontrados em Basic. A classe também fornece operadores e construtores para criar, atribuir e comparando **CStrings** e os tipos de dados de cadeia de caracteres C++ padrão. Porque `CString` não é derivado de `CObject`, você pode usar `CString` objetos independentemente da maioria da Microsoft Foundation Class Library (MFC).  
  
 `CString`objetos seguem "semântica de valor". Um `CString` objeto representa um valor exclusivo. Imagine um `CString` como uma cadeia de caracteres real, não como um ponteiro para uma cadeia de caracteres.  
  
 Um `CString` objeto representa uma sequência de um número variável de caracteres. `CString`objetos podem ser pensados como matrizes de caracteres.  
  
##  <a name="_core_unicode_and_mbcs_provide_portability"></a>Portabilidade de fornecer Unicode e MBCS  
 Com MFC versão 3.0 e posterior, MFC, incluindo `CString`, está habilitado para Unicode e conjuntos de caracteres multibyte (MBCS). Esse suporte mais fácil escrever aplicativos portáteis que você pode criar para caracteres Unicode ou ANSI. Para habilitar esse portabilidade, cada caractere em uma `CString` objeto é do tipo **TCHAR**, que é definida como `wchar_t` se você definir o símbolo **Unicode** quando você criar seu aplicativo, ou como `char` se não for. Um `wchar_t` caractere é 16 bits de largura. MBCS estará habilitada se você criar com o símbolo **MBCS** definido. MFC em si é criado com o o **MBCS** símbolo (para as bibliotecas NAFX) ou o **Unicode** símbolo (para as bibliotecas UAFX) definido.  
  
> [!NOTE]
>  O `CString` exemplos desta e o que acompanha os artigos em cadeias de caracteres mostram cadeias de caracteres literal formatadas corretamente para a portabilidade de Unicode, usando o **t** macro, que converte a cadeia de caracteres literal para o formulário:  
  
 `L"literal string"`  
  
> [!NOTE]
>  qual o compilador trata como uma cadeia de caracteres Unicode. Por exemplo, o código a seguir:  
  
 [!code-cpp[NVC_ATLMFC_Utilities#187](../atl-mfc-shared/codesnippet/cpp/string-data-management_1.cpp)]  
  
> [!NOTE]
>  é convertida como uma cadeia de caracteres Unicode se **Unicode** está definida ou como um ANSI de cadeia de caracteres se não. Para obter mais informações, consulte o artigo [suporte a Unicode e conjunto de caracteres Multibyte (MBCS)](../atl-mfc-shared/unicode-and-multibyte-character-set-mbcs-support.md).  
  
 Um `CString` objeto pode armazenar até **INT_MAX** (2.147.483.647) caracteres. O **TCHAR** tipo de dados é usado para obter ou definir caracteres individuais dentro de um `CString` objeto. Ao contrário das matrizes de caracteres, a `CString` classe tem um recurso de alocação de memória internos. Isso permite que `CString` objetos cresçam automaticamente conforme necessário (ou seja, você não precisa se preocupar sobre crescendo um `CString` objeto para ajustar mais cadeias de caracteres).  
  
##  <a name="_core_cstrings_and_const_char_pointers"></a>CStrings e ponteiros de char constantes  
 Um `CString` objeto também pode agir como uma cadeia de caracteres literal do estilo C (um `PCXSTR`, que é o mesmo que **char const\***  se não em Unicode). O [CSimpleStringT::operator PCXSTR](../atl-mfc-shared/reference/csimplestringt-class.md#operator_pcxstr) permite que o operador de conversão `CString` objetos a serem substituídos gratuitamente por ponteiros de caractere em chamadas de função. O **CString (LPCWSTR** `pszSrc` **)** construtor permite ponteiros de caracteres a serem substituídos por `CString` objetos.  
  
 É feita nenhuma tentativa para se Desdobrar `CString` objetos. Se você fizer dois `CString` objetos contendo `Chicago`, por exemplo, os caracteres em `Chicago` são armazenadas em dois locais. (Isso pode não ser verdadeiro para versões futuras do MFC, portanto você não deve depender de ele.)  
  
> [!NOTE]
>  Use o [CSimpleStringT::GetBuffer](../atl-mfc-shared/reference/csimplestringt-class.md#getbuffer) e [CSimpleStringT::ReleaseBuffer](../atl-mfc-shared/reference/csimplestringt-class.md#releasebuffer) funções de membro, quando você precisa acessar diretamente um `CString` como um ponteiro não constante para um caractere.  
  
> [!NOTE]
>  Use o [CStringT::AllocSysString](../atl-mfc-shared/reference/cstringt-class.md#allocsysstring) e [CStringT::SetSysString](../atl-mfc-shared/reference/cstringt-class.md#setsysstring) funções de membro para alocar e definir `BSTR` objetos usados na automação (anteriormente conhecida como automação OLE).  
  
> [!NOTE]
>  Sempre que possível, aloque `CString` objetos no quadro, em vez de no heap. Isso economiza memória e simplifica a passagem de parâmetro.  
  
 O `CString` classe não é implementada como uma classe de coleção de biblioteca Microsoft Foundation Class, embora `CString` objetos certamente podem ser armazenados como elementos em coleções.  
  
##  <a name="_core_cstring_reference_counting"></a>Contagem de referência de CString  
 A partir de MFC versão 4.0, quando [CStringT classe](../atl-mfc-shared/reference/cstringt-class.md) objetos forem copiados, MFC incrementa a contagem de referência em vez de copiar os dados. Isso torna passando parâmetros de valor e retornando `CString` objetos por valor mais eficiente. Essas operações fazer com que o construtor de cópia seja chamado, às vezes, mais de uma vez. Incrementar uma contagem de referência reduz essa sobrecarga para essas operações comuns e facilita o uso de `CString` uma opção mais atraente.  
  
 Como cada cópia é destruída, a contagem de referência no objeto original é reduzida. O original `CString` objeto não será destruído até sua contagem de referência é reduzida a zero.  
  
 Você pode usar o `CString` funções de membro [CSimpleStringT::LockBuffer](../atl-mfc-shared/reference/csimplestringt-class.md#lockbuffer) e [CSimpleStringT::UnlockBuffer](../atl-mfc-shared/reference/csimplestringt-class.md#unlockbuffer) para desabilitar ou habilitar a contagem de referência.  
  
## <a name="see-also"></a>Consulte também  
 [Tópicos gerais do MFC](../mfc/general-mfc-topics.md)

