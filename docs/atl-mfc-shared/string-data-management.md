---
title: Gerenciamento de dados de cadeia de caracteres | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- Unicode, string objects
ms.assetid: 0b53a542-eeb1-4108-9ada-6700645b6f8f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b42f637c487e27b8658bcd09389eec940bb1df05
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37880210"
---
# <a name="string-data-management"></a>Gerenciamento de dados da cadeia de caracteres
Visual C++ fornece várias maneiras para gerenciar dados de cadeia de caracteres:  
  
-   [Manipulação de cadeia de caracteres](../c-runtime-library/string-manipulation-crt.md) para trabalhar com cadeias de caracteres do estilo C terminada em nulo  
  
-   Funções de API do Win32 para o gerenciamento de cadeias de caracteres  
  
-   Classe do MFC [classe CStringT](../atl-mfc-shared/reference/cstringt-class.md), que fornece os objetos de cadeia de caracteres de flexível e dimensionável  
  
-   Classe [classe CStringT](../atl-mfc-shared/reference/cstringt-class.md), que fornece um objeto de cadeia de caracteres MFC independentes com a mesma funcionalidade que `CString`  
  
 Quase todos os programas funcionam com dados de cadeia de caracteres. Do MFC `CString` classe geralmente é a melhor solução para a manipulação de cadeia de caracteres flexível. Começando com a versão 7.0, `CString` pode ser usado em programas MFC ou independentes da MFC. A biblioteca do tempo de execução e `CString` dar suporte a cadeias de caracteres contendo caracteres multibyte de (horizontal), como na programação de Unicode ou MBCS.  
  
 Este artigo descreve os serviços de uso geral que a biblioteca de classes fornece relacionados a manipulação de cadeia de caracteres. Os tópicos abordados neste artigo incluem:  
  
-   [Portabilidade de Unicode e MBCS fornecer](#_core_unicode_and_mbcs_provide_portability)  
  
-   [CStrings e ponteiros de char const](#_core_cstrings_and_const_char_pointers)  
  
-   [Contagem de referência de CString](#_core_cstring_reference_counting)  
  
 O [classe CStringT](../atl-mfc-shared/reference/cstringt-class.md) classe oferece suporte para manipulação de cadeias de caracteres. Ele destina-se substituir e estender a funcionalidade normalmente fornecida pelo pacote de cadeia de caracteres de biblioteca de tempo de execução C. O `CString` classe fornece funções de membro e operadores para tratamento simplificada de cadeia de caracteres, semelhantes àqueles encontrados no Basic. A classe também fornece construtores e operadores para construir, atribuindo e comparando `CString`tipos de dados de cadeia de caracteres de s e C++ padrão. Porque `CString` não é derivado de `CObject`, você pode usar `CString` objetos independentemente da maioria da Microsoft Foundation Class Library (MFC).  
  
 `CString` objetos seguem "semântica de valor". Um `CString` objeto representa um valor exclusivo. Pense em um `CString` como uma cadeia de caracteres real, não como um ponteiro para uma cadeia de caracteres.  
  
 Um `CString` objeto representa uma sequência de um número variável de caracteres. `CString` objetos podem ser pensados como matrizes de caracteres.  
  
##  <a name="_core_unicode_and_mbcs_provide_portability"></a> Portabilidade de fornecer Unicode e MBCS  
 Com o MFC versão 3.0 e posterior, MFC, incluindo o `CString`, está habilitado para Unicode e conjuntos de caracteres multibyte (MBCS). Esse suporte torna mais fácil de escrever aplicativos portáteis que você pode criar para caracteres Unicode ou ANSI. Para habilitar essa portabilidade, cada caractere em uma `CString` objeto é do tipo TCHAR, que é definida como `wchar_t` se você definir o Unicode de símbolo quando você compila seu aplicativo ou como `char` se não for. Um `wchar_t` caractere é 16 bits de largura. MBCS é habilitado se você compilar com o MBCS de símbolo definido. MFC em si é criado com o símbolo de MBCS (para as bibliotecas NAFX) ou o símbolo Unicode (para as bibliotecas UAFX) definido.  
  
> [!NOTE]
>  O `CString` exemplos isso e os artigos que acompanha este artigo em cadeias de caracteres mostram cadeias de caracteres literais formatadas corretamente para fins de portabilidade de Unicode, usando a macro t, que converte a cadeia de caracteres literal para o formulário:  
  
 `L"literal string"`  
  
> [!NOTE]
>  qual o compilador trata como uma cadeia de caracteres Unicode. Por exemplo, o código a seguir:  
  
 [!code-cpp[NVC_ATLMFC_Utilities#187](../atl-mfc-shared/codesnippet/cpp/string-data-management_1.cpp)]  
  
> [!NOTE]
>  é traduzida como uma cadeia de caracteres Unicode se Unicode estiver definido ou como uma cadeia de caracteres ANSI se não. Para obter mais informações, consulte o artigo [suporte a Unicode e conjunto de caracteres Multibyte (MBCS)](../atl-mfc-shared/unicode-and-multibyte-character-set-mbcs-support.md).  
  
 Um `CString` objeto pode armazenar caracteres INT_MAX (2.147.483.647). O tipo de dados TCHAR é usado para obter ou definir caracteres individuais dentro de um `CString` objeto. Ao contrário das matrizes de caracteres, o `CString` classe tem uma funcionalidade de alocação de memória interna. Isso permite `CString` objetos para aumentar automaticamente conforme necessário (ou seja, você não precisa se preocupar sobre crescendo um `CString` objeto para ajustar mais cadeias de caracteres).  
  
##  <a name="_core_cstrings_and_const_char_pointers"></a> CStrings e ponteiros de char const  
 Um `CString` objeto também pode funcionar como uma cadeia de caracteres literal do estilo C (uma `PCXSTR`, que é igual a **char const\***  se não em Unicode). O [CSimpleStringT::operator PCXSTR](../atl-mfc-shared/reference/csimplestringt-class.md#operator_pcxstr) permite que o operador de conversão `CString` objetos a serem substituídos livremente para ponteiros de caractere em chamadas de função. O **CString (LPCWSTR** `pszSrc` **)** construtor permite que os ponteiros de caractere a ser substituído por `CString` objetos.  
  
 Nenhuma tentativa será feita para dobrar `CString` objetos. Se você fizer duas `CString` objetos que contêm `Chicago`, por exemplo, os caracteres em `Chicago` são armazenados em dois locais. (Isso pode não ser verdadeiro para versões futuras do MFC, portanto, você não deve depender de ele.)  
  
> [!NOTE]
>  Use o [CSimpleStringT::GetBuffer](../atl-mfc-shared/reference/csimplestringt-class.md#getbuffer) e [CSimpleStringT::ReleaseBuffer](../atl-mfc-shared/reference/csimplestringt-class.md#releasebuffer) funções de membro quando você precisa para acessar diretamente um `CString` como um ponteiro não constante para um caractere.  
  
> [!NOTE]
>  Use o [CStringT::AllocSysString](../atl-mfc-shared/reference/cstringt-class.md#allocsysstring) e [CStringT::SetSysString](../atl-mfc-shared/reference/cstringt-class.md#setsysstring) funções de membro para alocar e definir os objetos BSTR usados na automação (anteriormente conhecida como automação OLE).  
  
> [!NOTE]
>  Sempre que possível, aloque `CString` objetos no quadro, em vez de no heap. Isso economiza memória e simplifica a passagem de parâmetro.  
  
 O `CString` classe não é implementada como uma classe de coleção da biblioteca Microsoft Foundation Class, porém `CString` objetos certamente podem ser armazenados como elementos nas coleções.  
  
##  <a name="_core_cstring_reference_counting"></a> Contagem de referência de CString  
 A partir do MFC versão 4.0, quando [classe CStringT](../atl-mfc-shared/reference/cstringt-class.md) objetos forem copiados, MFC incrementa uma contagem de referência em vez de copiar os dados. Isso torna passando parâmetros por valor e retornando `CString` objetos por valor mais eficiente. Essas operações fazem com que o construtor de cópia a ser chamado, às vezes, mais de uma vez. Incrementar uma contagem de referência reduz essa sobrecarga para essas operações comuns e facilita o uso de `CString` uma opção mais atraente.  
  
 Como cada cópia for destruída, a contagem de referência no objeto original é diminuída. Original `CString` objeto será destruído até que sua contagem de referência é reduzida a zero.  
  
 Você pode usar o `CString` funções de membro [CSimpleStringT::LockBuffer](../atl-mfc-shared/reference/csimplestringt-class.md#lockbuffer) e [CSimpleStringT::UnlockBuffer](../atl-mfc-shared/reference/csimplestringt-class.md#unlockbuffer) para desabilitar ou habilitar a contagem de referência.  
  
## <a name="see-also"></a>Consulte também  
 [Tópicos gerais do MFC](../mfc/general-mfc-topics.md)

