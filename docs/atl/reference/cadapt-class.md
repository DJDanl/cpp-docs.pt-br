---
title: "Classe CAdapt | Microsoft Docs"
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
  - "ATL.CAdapt"
  - "ATL.CAdapt<T>"
  - "ATL::CAdapt"
  - "ATL::CAdapt<T>"
  - "CAdapt"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador address-of"
  - "objetos de adaptador"
  - "& operador, operador address-of"
  - "Classe CAdapt"
ms.assetid: 0bb695a5-72fe-43d1-8f39-7e4da6e34765
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CAdapt
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esse modelo é usado para incluir classes que redefinem o operador address\-of para retornar algo diferente do endereço do objeto.  
  
## Sintaxe  
  
```  
  
template <  
   class   
T  
>  
class CAdapt  
  
```  
  
#### Parâmetros  
 `T`  
 O tipo adaptado.  
  
## Membros  
  
### Construtores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAdapt::CAdapt](../Topic/CAdapt::CAdapt.md)|O construtor.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Const T& de CAdapt::operator](../Topic/CAdapt::operator%20const%20T&.md)|Retorna um `const` referência a `m_T`.|  
|[CAdapt::operator T&](../Topic/CAdapt::operator%20T&.md)|Retorna uma referência ao `m_T`.|  
|[CAdapt::operator \<](../Topic/CAdapt::operator%20%3C.md)|Compara um objeto do tipo adaptado com `m_T`.|  
|[CAdapt::operator \=](../Topic/CAdapt::operator%20=.md)|Atribui um objeto do tipo adaptado a `m_T`.|  
|[\=\= De CAdapt::operator](../Topic/CAdapt::operator%20==.md)|Compara um objeto do tipo adaptado com `m_T`.|  
  
### Membros de dados públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAdapt::m\_T](../Topic/CAdapt::m_T.md)|Os dados que está sendo adaptados.|  
  
## Comentários  
 `CAdapt` é um modelo simples usado para incluir classes que redefinem o operador address\-of \(`operator &`\) para retornar algo diferente do endereço do objeto. Exemplos de tais classes da ATL `CComBSTR`, `CComPtr`, e `CComQIPtr` classes e a classe de suporte COM do compilador, `_com_ptr_t`. Todas essas classes redefinem o operador address\-of para retornar o endereço de um de seus membros de dados \(um `BSTR` no caso de `CComBSTR`, e um ponteiro de interface no caso de outras classes\).  
  
 `CAdapt`da função principal é ocultar o operador address\-of definido pela classe `T`, mas ainda manter as características da classe adaptada.`CAdapt` desempenha essa função mantendo um membro público, [m\_T](../Topic/CAdapt::m_T.md), do tipo `T`, e definindo operadores de conversão, operadores de comparação e um construtor de cópia para permitir que especializações de `CAdapt` deve ser tratado como se fossem objetos do tipo `T`.  
  
 A classe do adaptador `CAdapt` é útil porque algumas classes do estilo contêiner esperam poder obter os endereços dos seus objetos contidos usando o operador address\-of. A redefinição do operador address\-of pode confundir esse requisito, normalmente causando erros de compilação e evitar o uso do tipo não adaptado com classes que espera "simplesmente funcionem".`CAdapt` Fornece uma maneira de contornar esses problemas.  
  
 Normalmente, você usará `CAdapt` quando quiser armazenar `CComBSTR`, `CComPtr`, `CComQIPtr`, ou `_com_ptr_t` objetos em uma classe de estilo do contêiner. Isso era mais comumente necessário para antes de contêineres da biblioteca padrão C\+\+ oferecer suporte para o padrão C\+\+ 11, mas C \+ \+ contêineres da biblioteca padrão 11 funcionam automaticamente com tipos que sobrecarregaram `operator&()`. A biblioteca padrão obtém isso internamente usando [std::addressof\(\)](../Topic/addressof.md) para obter os endereços verdadeiros dos objetos.  
  
## Requisitos  
 **Cabeçalho:** atlcomcli. h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)