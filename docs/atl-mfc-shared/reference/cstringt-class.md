---
title: "Classe de CStringT | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CString"
  - "CStringT"
  - "ATL::CStringT"
  - "ATL.CStringT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CStringT"
  - "classes compartilhadas, CStringT"
  - "cadeias de caracteres [C++], em ATL"
ms.assetid: 7cacc59c-425f-40f1-8f5b-6db921318ec9
caps.latest.revision: 33
caps.handback.revision: 22
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CStringT
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta classe representa um objeto de `CStringT` .  
  
## Sintaxe  
  
```  
  
      template< typename   
      BaseType  
      , class   
      StringTraits  
       >  
class CStringT :   
public CSimpleStringT<   BaseType,   _CSTRING_IMPL_::_MFCDLLTraitsCheck<      BaseType,      StringTraits   >   ::c_bIsMFCDLLTraits>  
```  
  
#### Parâmetros  
 `BaseType`  
 O tipo da classe de caractere de cadeia de caracteres.  Pode ser um dos seguintes:  
  
-   `char` \(para cadeias de caracteres ANSI\).  
  
-   `wchar_t` \(para cadeias de caracteres Unicode\).  
  
-   Para**TCHAR** \(ANSI e cadeias de caracteres Unicode\).  
  
 `StringTraits`  
 Determina se o suporte a biblioteca common language runtime \(CRT\) de As necessidades da classe de cadeia de caracteres e onde os recursos de cadeia de caracteres estão localizados.  Pode ser um dos seguintes:  
  
-   **Wchar\_t de strtraitatl\<** &#124; `char` &#124; **TCHAR de chtraitscrt\<, wchar\_t** &#124; `char` &#124; **TCHAR \> \>**  
  
     A classe requer suporte e as pesquisas de CRT para cadeias de caracteres de recurso no módulo especificado por `m_hInstResource` \(um membro da classe do módulo do aplicativo\).  
  
-   **Wchar\_t de strtraitatl\<** &#124; `char` &#124; **TCHAR de chtraitsos\<, wchar\_t** &#124; `char` &#124; **TCHAR \> \>**  
  
     A classe não requer suporte e as pesquisas de CRT para cadeias de caracteres de recurso no módulo especificado por `m_hInstResource` \(um membro da classe do módulo do aplicativo\).  
  
-   **Wchar\_t de strtraitmfc\<** &#124; `char` &#124; **TCHAR de chtraitscrt\<, wchar\_t** &#124; `char` &#124; **TCHAR \> \>**  
  
     A classe requer suporte e as pesquisas de CRT para cadeias de caracteres de recurso usando o algoritmo de pesquisa MFC do padrão.  
  
-   **Wchar\_t de strtraitmfc\<** &#124; `char` &#124; **TCHAR de chtraitsos\<, wchar\_t** &#124; `char` &#124; **TCHAR \> \>**  
  
     A classe não requer suporte e as pesquisas de CRT para cadeias de caracteres de recurso usando o algoritmo de pesquisa MFC do padrão.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CStringT::CStringT](../Topic/CStringT::CStringT.md)|Constrói um objeto de `CStringT` de várias maneiras.|  
|[CStringT::~CStringT](../Topic/CStringT::~CStringT.md)|For um objeto de `CStringT` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CStringT::AllocSysString](../Topic/CStringT::AllocSysString.md)|Atribui `BSTR` de dados de `CStringT` .|  
|[CStringT::AnsiToOem](../Topic/CStringT::AnsiToOem.md)|Faz uma conversão no lugar do conjunto de caracteres ANSI ao conjunto de caracteres de OEM.|  
|[CStringT::AppendFormat](../Topic/CStringT::AppendFormat.md)|Appends formatada de dados a um objeto existente de `CStringT` .|  
|[CStringT::Collate](../Topic/CStringT::Collate.md)|Compara duas cadeias de caracteres \(diferencia maiúsculas de minúsculas, informações específicas do usa\).|  
|[CStringT::CollateNoCase](../Topic/CStringT::CollateNoCase.md)|Compara duas cadeias de caracteres \(sem diferenciação de maiúsculas e minúsculas, informações específicas do usa\).|  
|[CStringT::Compare](../Topic/CStringT::Compare.md)|Compara duas cadeias de caracteres \(diferencia maiúsculas de minúsculas\).|  
|[CStringT::CompareNoCase](../Topic/CStringT::CompareNoCase.md)|Compara duas cadeias de caracteres \(sem diferenciação de maiúsculas e minúsculas\).|  
|[CStringT::Delete](../Topic/CStringT::Delete.md)|Exclui um caractere ou mais caracteres de uma cadeia de caracteres.|  
|[CStringT::Find](../Topic/CStringT::Find.md)|Localiza um caractere ou uma subcadeia de caracteres em uma cadeia de caracteres maior.|  
|[CStringT::FindOneOf](../Topic/CStringT::FindOneOf.md)|Localiza o primeiro caractere correspondente de um dataset.|  
|[CStringT::Format](../Topic/CStringT::Format.md)|Formata a cadeia de caracteres como `sprintf` faz.|  
|[CStringT::FormatMessage](../Topic/CStringT::FormatMessage.md)|Formata uma cadeia de mensagem.|  
|[CStringT::FormatMessageV](../Topic/CStringT::FormatMessageV.md)|Formata uma cadeia de mensagem usando uma lista de argumentos variável.|  
|[CStringT::FormatV](../Topic/CStringT::FormatV.md)|Formata a cadeia de caracteres usando uma lista variável de argumentos.|  
|[CStringT::GetEnvironmentVariable](../Topic/CStringT::GetEnvironmentVariable.md)|Defina a cadeia de caracteres ao valor da variável de ambiente especificada.|  
|[CStringT::Insert](../Topic/CStringT::Insert.md)|Insere um único caractere ou uma subcadeia de caracteres no índice especificado dentro da cadeia de caracteres.|  
|[CStringT::Left](../Topic/CStringT::Left.md)|Em a parte superior esquerda de uma cadeia de caracteres.|  
|[CStringT::LoadString](../Topic/CStringT::LoadString.md)|Carrega um objeto existente de `CStringT` de um recurso do windows.|  
|[CStringT::MakeLower](../Topic/CStringT::MakeLower.md)|Converte todos os caracteres na cadeia de caracteres para caracteres maiúsculos.|  
|[CStringT::MakeReverse](../Topic/CStringT::MakeReverse.md)|Inverte a cadeia de caracteres.|  
|[CStringT::MakeUpper](../Topic/CStringT::MakeUpper.md)|Converte todos os caracteres na cadeia de caracteres para caracteres maiúsculos.|  
|[CStringT::Mid](../Topic/CStringT::Mid.md)|Em a parte do meio de uma cadeia de caracteres.|  
|[CStringT::OemToAnsi](../Topic/CStringT::OemToAnsi.md)|Faz uma conversão no lugar do conjunto de caracteres de OEM ao conjunto de caracteres ANSI.|  
|[CStringT::Remove](../Topic/CStringT::Remove.md)|Removes indicou caracteres de uma cadeia de caracteres.|  
|[CStringT::Replace](../Topic/CStringT::Replace.md)|Replaces indicou caracteres com outros caracteres.|  
|[CStringT::ReverseFind](../Topic/CStringT::ReverseFind.md)|Localiza um caractere dentro de uma cadeia de caracteres maior; parte do final.|  
|[CStringT::Right](../Topic/CStringT::Right.md)|Em a parte direita de uma cadeia de caracteres.|  
|[CStringT::SetSysString](../Topic/CStringT::SetSysString.md)|Define um objeto existente de `BSTR` com dados de um objeto de `CStringT` .|  
|[CStringT::SpanExcluding](../Topic/CStringT::SpanExcluding.md)|Extrai os caracteres de uma cadeia de caracteres, começando com o primeiro caractere, que não estão no conjunto de caracteres identificados por `pszCharSet`.|  
|[CStringT::SpanIncluding](../Topic/CStringT::SpanIncluding.md)|Extrai uma subcadeia de caracteres que contém somente os caracteres em um dataset.|  
|[CStringT::Tokenize](../Topic/CStringT::Tokenize.md)|Tokens especificados extratos em uma cadeia de caracteres de destino.|  
|[CStringT::Trim](../Topic/CStringT::Trim.md)|Corta todos os caracteres à esquerda e direita de espaço em branco de cadeia de caracteres.|  
|[CStringT::TrimLeft](../Topic/CStringT::TrimLeft.md)|Guarnições que levam caracteres de espaço em branco de cadeia de caracteres.|  
|[CStringT::TrimRight](../Topic/CStringT::TrimRight.md)|Guarnições que arraste caracteres de espaço em branco de cadeia de caracteres.|  
  
### Operadores  
  
|||  
|-|-|  
|[CStringT::operator \=](../Topic/CStringT::operator%20=.md)|Atribuir um novo valor a um objeto de `CStringT` .|  
|[CStringT::operator \+](../Topic/CStringT::operator%20+.md)|Concatena duas cadeias de caracteres ou um caractere e uma cadeia de caracteres.|  
|[CStringT::operator \+\=](../Topic/CStringT::operator%20+=.md)|Concatena uma nova cadeia de caracteres ao final de uma cadeia de caracteres existente.|  
|[\=\= De CStringT::operator](../Topic/CStringT::operator%20==.md)|Determina se duas cadeias de caracteres são logicamente iguais.|  
|[CStringT::operator\! \=](../Topic/CStringT::operator%20!=.md)|Determina se duas cadeias de caracteres não são logicamente iguais.|  
|[CStringT::operator \<](../Topic/CStringT::operator%20%3C.md)|Determina se a cadeia de caracteres no lado esquerdo do operador é menor do que a cadeia de caracteres no lado direito.|  
|[CStringT::operator \>](../Topic/CStringT::operator%20%3E.md)|Determina se a cadeia de caracteres no lado esquerdo do operador é maior do que a cadeia de caracteres no lado direito.|  
|[\<\= De CStringT::operator](../Topic/CStringT::operator%20%3C=.md)|Determina se a cadeia de caracteres no lado esquerdo do operador é menor ou igual a cadeia de caracteres no lado direito.|  
|[CStringT::operator \> \=](../Topic/CStringT::operator%20%3E=.md)|Determina se a cadeia de caracteres no lado esquerdo do operador é maior ou igual a cadeia de caracteres no lado direito.|  
  
## Comentários  
 `CStringT` herda de [classe de CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md).  Os recursos avançados, como a manipulação de caractere, classificação, e procurando, são implementados por `CStringT`.  
  
> [!NOTE]
>  Os objetos de`CStringT` são capazes de lançar exceções.  Isso ocorre quando um objeto de `CStringT` fora de memória por alguma razão.  
  
 Um objeto de `CStringT` consiste em uma seqüência de caracteres de comprimento variável de caracteres.  `CStringT` fornece funções e operadores que usam sintaxe semelhante a de básico.  Concatenação e operadores de comparação, juntamente com gerenciamento de memória, simplificado tornam mais fácil de usar objetos `CStringT` de matrizes de caracteres comuns.  
  
> [!NOTE]
>  Embora seja possível criar instâncias de `CStringT` que contenham caracteres nulos inseridos, recomendamos contra ele.  Os métodos e os operadores de chamada em objetos de `CStringT` que contenham caracteres nulos inseridos podem produzir resultados indesejados.  
  
 Usando combinações diferentes dos parâmetros de `BaseType` e de `StringTraits` , objetos podem vir de `CStringT` nos seguintes tipos, que são foram predefinidos pelas bibliotecas de ATL.  
  
 Se ele usando em um aplicativo de ATL:  
  
 `CString`, `CStringA`, e `CStringW` são exportados de DLL MFC \(MFC90.DLL\), nunca de DLL do usuário.  Isso é feito para impedir que `CStringT` multiplicar é definido.  
  
> [!NOTE]
>  Se você encontrou erros de vinculador exportar `CString`\- classe derivada de uma DLL de extensão MFC no Visual C\+\+ .NET 2002 e aplicada a alternativa conforme descrito no artigo de Base de Dados de Conhecimento, “vinculando erros quando você importar classes Derivadas CString\-” \(Q309801\), você deve remover o código de solução alternativa, porque isso foi corrigido no Visual C\+\+ .NET 2003.  Você pode localizar artigos de Base de Dados de Conhecimento da Biblioteca MSDN em um CD\-ROM [http:\/\/support.microsoft.com\/support](http://support.microsoft.com/support)ou.  
  
 Os seguintes tipos de cadeias de caracteres estão disponíveis em aplicativos baseados MFC\-:  
  
|Tipo de CStringT|Declaração|  
|----------------------|----------------|  
|`CStringA`|Uma cadeia de caracteres de tipo de caractere ANSI com suporte de CRT.|  
|`CStringW`|Uma cadeia de caracteres de tipo de caracteres Unicode com suporte de CRT.|  
|`CString`|ANSI e tipos de caractere Unicode com suporte de CRT.|  
  
 Os seguintes tipos de cadeias de caracteres estão disponíveis em projetos **ATL\_CSTRING\_NO\_CRT** onde ela está definida:  
  
|Tipo de CStringT|Declaração|  
|----------------------|----------------|  
|**CAtlStringA**|Uma cadeia de caracteres de tipo de caractere ANSI sem suporte de CRT.|  
|**CAtlStringW**|Uma cadeia de caracteres de tipo de caracteres Unicode sem suporte de CRT.|  
|**CAtlString**|ANSI e tipos de caractere Unicode sem suporte de CRT.|  
  
 Os seguintes tipos de cadeias de caracteres estão disponíveis em projetos **ATL\_CSTRING\_NO\_CRT** onde não é definida:  
  
|Tipo de CStringT|Declaração|  
|----------------------|----------------|  
|**CAtlStringA**|Uma cadeia de caracteres de tipo de caractere ANSI com suporte de CRT.|  
|**CAtlStringW**|Uma cadeia de caracteres de tipo de caracteres Unicode com suporte de CRT.|  
|**CAtlString**|ANSI e tipos de caractere Unicode com suporte de CRT.|  
  
 Os objetos de`CString` também têm as seguintes características:  
  
-   Os objetos de`CStringT` pode crescer como resultado de operações de concatenação.  
  
-   Os objetos de`CStringT` seguem a semântica de “valor”. Pense em um objeto de `CStringT` como uma cadeia de caracteres real, não como um ponteiro para uma cadeia de caracteres.  
  
-   Você pode substituir livremente entre objetos de `CStringT` para argumentos de função de `PCXSTR` .  
  
-   Gerenciamento de memória personalizado para buffers de cadeia de caracteres.  Para obter mais informações, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).  
  
## CStringT tipos predefinidos  
 Porque `CStringT` usa um argumento de modelo para definir o tipo de caracteres \(ou\) [wchar\_t](../../c-runtime-library/standard-types.md)[char](../../c-runtime-library/standard-types.md)suportados, tipos de parâmetro do método pode ser complicado às vezes.  Para simplificar esse problema, um conjunto de tipos predefinidos é definido e usado durante a classe de `CStringT` .  A tabela a seguir lista os tipos:  
  
|Nome|Descrição|  
|----------|---------------|  
|`XCHAR`|Um único caractere \( `wchar_t` ou `char`\) com o mesmo tipo de caractere que o objeto de `CStringT` .|  
|**YCHAR**|Um único caractere \( `wchar_t` ou `char`\) com o tipo de caractere oposto como o objeto de `CStringT` .|  
|`PXSTR`|Um ponteiro para uma cadeia de caracteres \( `wchar_t` ou `char`\) com o mesmo tipo de caractere que o objeto de `CStringT` .|  
|**PYSTR**|Um ponteiro para uma cadeia de caracteres \( `wchar_t` ou `char`\) com o tipo de caractere oposto como o objeto de `CStringT` .|  
|`PCXSTR`|Um ponteiro para uma cadeia de caracteres de **const** \( `wchar_t` ou `char`\) com o mesmo tipo de caractere que o objeto de `CStringT` .|  
|**PCYSTR**|Um ponteiro para uma cadeia de caracteres de **const** \( `wchar_t` ou `char`\) com o tipo de caractere oposto como o objeto de `CStringT` .|  
  
> [!NOTE]
>  O código que os métodos indocumentados anteriormente usados de `CString` \(como **AssignCopy**\) devem ser substituídos pelo código que usa os seguintes métodos documentados de `CStringT` \(como `GetBuffer` ou `ReleaseBuffer`\).  Esses métodos são herdadas de `CSimpleStringT`.  
  
## Hierarquia de herança  
 [CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md)  
  
 `CStringT`  
  
## Requisitos  
  
|Header|Para uso|  
|------------|--------------|  
|cstringt.h|Objetos de cadeia de caracteres MFC \- somente|  
|atlstr.h|Objetos de cadeia de caracteres não MFC|  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [ATL\/MFC compartilhasse classes](../../atl-mfc-shared/atl-mfc-shared-classes.md)   
 [Classe de CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md)