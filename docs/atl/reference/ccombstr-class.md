---
title: "CComBSTR - classe | Microsoft Docs"
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
  - "ATL::CComBSTR"
  - "CComBSTR"
  - "ATL.CComBSTR"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "BSTRs, wrapper"
  - "CComBSTR"
  - "CComBSTR - classe"
ms.assetid: 8fea1879-a05e-47a5-a803-8dec60eaa534
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CComBSTR - classe
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe é um wrapper para `BSTR`S.  
  
## Sintaxe  
  
```  
  
class CComBSTR  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComBSTR::CComBSTR](../Topic/CComBSTR::CComBSTR.md)|o construtor.|  
|[CComBSTR::~CComBSTR](../Topic/CComBSTR::~CComBSTR.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComBSTR::Append](../Topic/CComBSTR::Append.md)|Acrescenta uma cadeia de caracteres a `m_str`.|  
|[CComBSTR::AppendBSTR](../Topic/CComBSTR::AppendBSTR.md)|Acrescenta `BSTR` a `m_str`.|  
|[CComBSTR::AppendBytes](../Topic/CComBSTR::AppendBytes.md)|Acrescenta um número de bytes especificado a `m_str`.|  
|[CComBSTR::ArrayToBSTR](../Topic/CComBSTR::ArrayToBSTR.md)|Cria `BSTR` do primeiro caractere de cada elemento no safearray e anexá\-la ao objeto de `CComBSTR` .|  
|[CComBSTR::AssignBSTR](../Topic/CComBSTR::AssignBSTR.md)|Atribui `BSTR` a `m_str`.|  
|[CComBSTR::Attach](../Topic/CComBSTR::Attach.md)|Anexa `BSTR` ao objeto de `CComBSTR` .|  
|[CComBSTR::BSTRToArray](../Topic/CComBSTR::BSTRToArray.md)|Cria um safearray unidimensional com base zero, onde cada elemento da matriz é um caractere de objeto de `CComBSTR` .|  
|[CComBSTR::ByteLength](../Topic/CComBSTR::ByteLength.md)|Retorna o comprimento de `m_str` em bytes.|  
|[CComBSTR::Copy](../Topic/CComBSTR::Copy.md)|Retorna uma cópia de `m_str`.|  
|[CComBSTR::CopyTo](../Topic/CComBSTR::CopyTo.md)|Retorna uma cópia de `m_str` através de um parâmetro de **\[out\]**|  
|[CComBSTR::Detach](../Topic/CComBSTR::Detach.md)|Dispara `m_str` do objeto de `CComBSTR` .|  
|[CComBSTR::Empty](../Topic/CComBSTR::Empty.md)|Libera `m_str`.|  
|[CComBSTR::Length](../Topic/CComBSTR::Length.md)|Retorna o comprimento de `m_str`.|  
|[CComBSTR::LoadString](../Topic/CComBSTR::LoadString.md)|Carrega um recurso de cadeia de caracteres.|  
|[CComBSTR::ReadFromStream](../Topic/CComBSTR::ReadFromStream.md)|Carrega um objeto de `BSTR` de um fluxo.|  
|[CComBSTR::ToLower](../Topic/CComBSTR::ToLower.md)|Converte a cadeia de caracteres em minúsculas.|  
|[CComBSTR::ToUpper](../Topic/CComBSTR::ToUpper.md)|Converte a cadeia de caracteres para maiúsculas.|  
|[CComBSTR::WriteToStream](../Topic/CComBSTR::WriteToStream.md)|Salva `m_str` em um fluxo.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComBSTR::operator BSTR](../Topic/CComBSTR::operator%20BSTR.md)|Converte um objeto de `CComBSTR` a `BSTR`.|  
|[CComBSTR::operator\!](../Topic/CComBSTR::operator%20!.md)|Retorna `true` ou `false`, dependendo se `m_str`é `NULL`.|  
|[CComBSTR::operator\! \=](../Topic/CComBSTR::operator%20!=.md)|Compara `CComBSTR` com uma cadeia de caracteres.|  
|[CComBSTR::operator &](../Topic/CComBSTR::operator%20&.md)|Retorna o endereço de `m_str`.|  
|[CComBSTR::operator \+\=](../Topic/CComBSTR::operator%20+=.md)|Acrescenta `CComBSTR` ao objeto.|  
|[CComBSTR::operator \<](../Topic/CComBSTR::operator%20%3C.md)|Compara `CComBSTR` com uma cadeia de caracteres.|  
|[CComBSTR::operator \=](../Topic/CComBSTR::operator%20=.md)|Atribui um valor a `m_str`.|  
|[\=\= De CComBSTR::operator](../Topic/CComBSTR::operator%20==.md)|Compara `CComBSTR` com uma cadeia de caracteres.|  
|[CComBSTR::operator \>](../Topic/CComBSTR::operator%20%3E.md)|Compara `CComBSTR` com uma cadeia de caracteres.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComBSTR::m\_str](../Topic/CComBSTR::m_str.md)|Contém `BSTR` associado ao objeto de `CComBSTR` .|  
  
## Comentários  
 a classe de `CComBSTR` é um wrapper para `BSTR`s, que são cadeias de caracteres comprimento\-prefixadas.  O comprimento é armazenado como um todo no local da memória que precede dados a cadeia de caracteres.  
  
 [BSTR](http://msdn.microsoft.com/pt-br/1b2d7d2c-47af-4389-a6b6-b01b7e915228) NULL\- é encerrado após o caractere a contagem o último mas também pode conter caracteres nulos inseridos dentro da cadeia de caracteres.  O comprimento da cadeia de caracteres é determinado pelo número de caracteres, não o primeiro caractere nulo.  
  
> [!NOTE]
>  A classe de `CComBSTR` fornece um número de membros \(construtores, operadores de atribuição, e operadores de comparação\) que leva ANSI ou cadeias de caracteres Unicode como argumentos.  As versões ANSI de essas funções são menos eficiente do que suas contrapartes Unicode como cadeias de caracteres Unicode temporário internamente geralmente são criadas.  Para eficiência, use as versões Unicode sempre que possível.  
  
> [!NOTE]
>  Devido ao comportamento de pesquisa melhor implementada no Visual Studio .NET, o código como `bstr = L"String2" + bstr;`, que podem ter criado em versões anteriores, em vez de isso deve ser implementado como `bstr = CStringW(L"String2") + bstr`.  
  
 Para obter uma lista de cuidados ao usar `CComBSTR`, consulte [programação com CComBSTR](../../atl/programming-with-ccombstr-atl.md).  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Macros de conversão de cadeia de caracteres de ATL e de MFC](../Topic/ATL%20and%20MFC%20String%20Conversion%20Macros.md)