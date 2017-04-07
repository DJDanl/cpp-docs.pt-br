---
title: Classe network_link_registry | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- network_link_registry
- AGENTS/concurrency::network_link_registry
- AGENTS/concurrency::network_link_registry::add
- AGENTS/concurrency::network_link_registry::begin
- AGENTS/concurrency::network_link_registry::contains
- AGENTS/concurrency::network_link_registry::count
- AGENTS/concurrency::network_link_registry::remove
dev_langs:
- C++
helpviewer_keywords:
- network_link_registry class
ms.assetid: 3e7b4097-09f1-4252-964e-b15b8f7f7fc6
caps.latest.revision: 20
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: 28c13f1e2bf80624da3a7aba441944c051790d27
ms.lasthandoff: 03/17/2017

---
# <a name="networklinkregistry-class"></a>Classe network_link_registry
O `network_link_registry` gerencia a classe base abstrata os links entre os blocos de origem e destino.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class _Block>
class network_link_registry;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_Block`  
 O bloco tipo de dados que estão sendo armazenados na `network_link_registry`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`const_pointer`|Um tipo que fornece um ponteiro para um `const` elemento em uma `network_link_registry` objeto.|  
|`const_reference`|Um tipo que fornece uma referência a um `const` elemento armazenado em uma `network_link_registry` objeto para ler e executar operações constantes.|  
|`iterator`|Um tipo que fornece um iterador que pode ler ou modificar qualquer elemento em uma `network_link_registry` objeto.|  
|`type`|Um tipo que representa o tipo de bloco armazenado na `network_link_registry` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[add](#add)|Quando substituído em uma classe derivada, adiciona um link para o `network_link_registry` objeto.|  
|[begin](#begin)|Quando substituído em uma classe derivada, retorna um iterador para o primeiro elemento no `network_link_registry` objeto.|  
|[contém](#contains)|Quando substituído em uma classe derivada, pesquisa a `network_link_registry` objeto para um bloco especificado.|  
|[count](#count)|Quando substituído em uma classe derivada, retorna o número de itens de `network_link_registry` objeto.|  
|[remove](#remove)|Quando substituído em uma classe derivada, remove um bloco especificado a partir de `network_link_registry` objeto.|  
  
## <a name="remarks"></a>Comentários  
 O `network link registry` não é seguro para acesso simultâneo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `network_link_registry`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="add"></a>Adicionar 

 Quando substituído em uma classe derivada, adiciona um link para o `network_link_registry` objeto.  
  
```
virtual void add(_EType _Link) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Link`  
 Um ponteiro para um bloco a ser adicionado.  
  
##  <a name="begin"></a>começar 

 Quando substituído em uma classe derivada, retorna um iterador para o primeiro elemento no `network_link_registry` objeto.  
  
```
virtual iterator begin() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que trata o primeiro elemento no `network_link_registry` objeto.  
  
### <a name="remarks"></a>Comentários  
 O estado final do iterador é indicado por um `NULL` link.  
  
##  <a name="contains"></a>contém 

 Quando substituído em uma classe derivada, pesquisa a `network_link_registry` objeto para um bloco especificado.  
  
```
virtual bool contains(_EType _Link) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Link`  
 Um ponteiro para um bloco que está sendo procurado no `network_link_registry` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o bloco for encontrado, `false` caso contrário.  
  
##  <a name="count"></a>Contagem 

 Quando substituído em uma classe derivada, retorna o número de itens de `network_link_registry` objeto.  
  
```
virtual size_t count() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens no objeto `network_link_registry`.  
  
##  <a name="remove"></a>Remover 

 Quando substituído em uma classe derivada, remove um bloco especificado a partir de `network_link_registry` objeto.  
  
```
virtual bool remove(_EType _Link) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Link`  
 Um ponteiro para um bloco a ser removido, se encontrado.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o link foi encontrado e removido, `false` caso contrário.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe single_link_registry](single-link-registry-class.md)   
 [Classe multi_link_registry](multi-link-registry-class.md)

