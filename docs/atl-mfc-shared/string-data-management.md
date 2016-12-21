---
title: "Gerenciamento de dados de cadeia de caracteres | Microsoft Docs"
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
  - "Unicode, objetos de cadeia de caracteres"
ms.assetid: 0b53a542-eeb1-4108-9ada-6700645b6f8f
caps.latest.revision: 15
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Gerenciamento de dados de cadeia de caracteres
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Visual C\+\+ fornece várias maneiras para gerenciar dados de cadeia de caracteres:  
  
-   [Manipulação da cadeia de caracteres](../c-runtime-library/string-manipulation-crt.md) para trabalhar com cadeias de caracteres NULL\- terminadas C de estilo  
  
-   Funções da API do Win32 para gerenciar cadeias de caracteres  
  
-   A classe [Classe de CStringT](../atl-mfc-shared/reference/cstringt-class.md)MFC, que fornece flexível, cadeia de caracteres redimensionável objetos  
  
-   [Classe de CStringT](../atl-mfc-shared/reference/cstringt-class.md)classe, que fornece um objeto MFC\- independente da cadeia de caracteres com a mesma funcionalidade que `CString`  
  
 Quase todos os programas trabalham com dados de cadeia de caracteres.  A classe de `CString` MFC geralmente é a melhor solução para manipulação flexível de cadeia de caracteres.  Iniciando com a versão 7,0, `CString` pode ser usado em um aplicativo MFC ou em programas MFC\- independentes.  A biblioteca e `CString` de tempo de execução suportam as cadeias de caracteres que contém caracteres \(largos\) de multibyte, como em Unicode ou na programação de MBCS.  
  
 Este artigo descreve serviços comumente usados que a biblioteca de classe fornece relacionado a manipulação de cadeia de caracteres.  Os tópicos abordados em este artigo incluem:  
  
-   [Unicode fornecem a portabilidade e MBCS](#_core_unicode_and_mbcs_provide_portability)  
  
-   [CStrings e o carbonizam ponteiros const](#_core_cstrings_and_const_char_pointers)  
  
-   [Contagem de referência de CString](#_core_cstring_reference_counting)  
  
 A classe de [Classe de CStringT](../atl-mfc-shared/reference/cstringt-class.md) fornece suporte para manipulando cadeias de caracteres.  Pretende\-se substituir e estender a funcionalidade fornecida normalmente pelo pacote de cadeia de caracteres de biblioteca em tempo de execução de C.  As funções de membro e os operadores de fontes da classe de `CString` para manipulação simplificada de cadeia de caracteres, semelhante àquelas encontrados em básico.  A classe também fornece construtores e operadores para construir, atribua, e comparar **CStrings** e tipos de dados de cadeia de caracteres do padrão C\+\+.  Porque `CString` não é derivado de `CObject`, você pode usar objetos de `CString` independentemente da maioria de biblioteca de classes da Microsoft foundation \(MFC\).  
  
 Os objetos de`CString` seguem a semântica de “valor”. Um objeto de `CString` representa um único valor.  Pense em `CString` como uma cadeia de caracteres real, não como um ponteiro para uma cadeia de caracteres.  
  
 Um objeto de `CString` representa uma seqüência de um número variável de caracteres.  Os objetos de`CString` podem ser considerados como matrizes de caracteres.  
  
##  <a name="_core_unicode_and_mbcs_provide_portability"></a> Unicode fornecem a portabilidade e MBCS  
 Com versão MFC 3,0 e posterior, o MFC, incluindo `CString`, é habilitado para Unicode e conjuntos de caracteres de multibyte \(MBCS\).  Esse suporte torna mais fácil para você escrever aplicativos portáteis que você pode criar para caracteres Unicode ou ANSI.  Para ativar essa portabilidade, cada caractere em um objeto de `CString` é do tipo **TCHAR**, que é definido como `wchar_t` se você definir o símbolo **\_UNICODE** quando você compila seu aplicativo, ou como `char` caso contrário.  Um caractere de `wchar_t` é 16 bits de largura.  MBCS é ativado se você compilar com o símbolo **\_MBCS** definiu.  O MFC próprio é compilado com o símbolo de **\_MBCS** \(para bibliotecas de NAFX\) ou o símbolo de **\_UNICODE** \(para bibliotecas de UAFX\) definido.  
  
> [!NOTE]
>  Exemplos de `CString` em este e os artigos de rastreamento em cadeias de caracteres mostram as cadeias de caracteres literais formatadas corretamente para a portabilidade Unicode, usando a macro de **\_T** , que converte a cadeia de caracteres literal para o formulário:  
  
 `L"literal string"`  
  
> [!NOTE]
>  qual o compilador trata como uma cadeia de caracteres Unicode.  Por exemplo, o seguinte código:  
  
 [!code-cpp[NVC_ATLMFC_Utilities#187](../atl-mfc-shared/codesnippet/CPP/string-data-management_1.cpp)]  
  
> [!NOTE]
>  ele é convertido como uma cadeia de caracteres Unicode ou se **\_UNICODE** é definido como uma cadeia de caracteres ANSI caso contrário.  Para obter mais informações, consulte o artigo [Suporte a Unicode e Multibyte Character Set \(MBCS\)](../atl-mfc-shared/unicode-and-multibyte-character-set-mbcs-support.md).  
  
 Um objeto de `CString` pode armazenar até **INT\_MAX** \(2.147.483.647\) caracteres.  O tipo de dados de **TCHAR** é usado para obter ou definir os caracteres individuais dentro de `CString` objeto.  A o contrário das matrizes de caracteres, a classe de `CString` tem um recurso interno de alocação de memória.  Isso permite que objetos de `CString` cresçam automaticamente conforme necessário \(ou seja, você não tem que se preocupar sobre crescimento de um objeto de `CString` para ajustar as cadeias de caracteres mais longas\).  
  
##  <a name="_core_cstrings_and_const_char_pointers"></a> CStrings e o carbonizam ponteiros const  
 Um objeto de `CString` também pode funcionar como uma cadeia de caracteres literal ctype de estilo \( `PCXSTR`, que é a mesma que **const char\*** se não em Unicode\).  O operador de conversão de [CSimpleStringT::operator PCXSTR](../Topic/CSimpleStringT::operator%20PCXSTR.md) permite que objetos de `CString` são substituídos distribuído para ponteiros de caracteres nas chamadas de função.  O construtor de **CString\( LPCWSTR**`pszSrc`**\)** permite que os ponteiros de caracteres são substituídos para objetos de `CString` .  
  
 Nenhuma tentativa é feita para dobrar objetos de `CString` .  Se você fizer dois objetos de `CString` que contêm `Chicago`, por exemplo, os caracteres em `Chicago` são armazenados em dois locais.  \(Isso não pode ser verdadeiro de versões futuras MFC, para que você não deve depender de ele.\)  
  
> [!NOTE]
>  Use as funções de membro de [CSimpleStringT::GetBuffer](../Topic/CSimpleStringT::GetBuffer.md) e de [CSimpleStringT::ReleaseBuffer](../Topic/CSimpleStringT::ReleaseBuffer.md) quando você precisa acessar diretamente `CString` como um ponteiro nonconstant a um caractere.  
  
> [!NOTE]
>  Use as funções de membro de [CStringT::AllocSysString](../Topic/CStringT::AllocSysString.md) e de [CStringT::SetSysString](../Topic/CStringT::SetSysString.md) para atribuir e definir objetos de `BSTR` usados na automação \(anteriormente conhecido como a automação OLE.\)  
  
> [!NOTE]
>  Sempre que possível, atribua objetos de `CString` no quadro em vez de no heap.  Isso economiza memória e simplifica transmissão de parâmetro.  
  
 A classe de `CString` não é implementada como uma classe de coleção de biblioteca de classes da Microsoft foundation, embora os objetos de `CString` certamente podem ser armazenados como elementos em coleções.  
  
##  <a name="_core_cstring_reference_counting"></a> Contagem de referência de CString  
 Até a data de versão 4,0 MFC, enquanto objetos de [Classe de CStringT](../atl-mfc-shared/reference/cstringt-class.md) são copiados, o MFC incrementa uma contagem de referência em vez de copiar os dados.  Isso torna passar parâmetros por valor e retornar objetos de `CString` pelo valor mais eficiente.  Essas operações faz com que o construtor de impressão para ser chamado às vezes mais de uma vez.  Incrementar uma contagem de referência que reduz sobrecarga para essas operações comuns e faz\-se usando `CString` uma opção mais atrativas.  
  
 Como cada cópia é destruída, contagem de referência no objeto original é decrescida.  O objeto de `CString` de original não é destruído até que a contagem de referência está reduzida a zero.  
  
 Você pode usar as funções de membro [CSimpleStringT::LockBuffer](../Topic/CSimpleStringT::LockBuffer.md) e [CSimpleStringT::UnlockBuffer](../Topic/CSimpleStringT::UnlockBuffer.md) de `CString` para ativar ou desativar contagem de referência.  
  
## Consulte também  
 [Tópicos MFC gerais](../mfc/general-mfc-topics.md)