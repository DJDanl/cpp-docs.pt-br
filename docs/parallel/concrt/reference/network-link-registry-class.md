---
title: Classe network_link_registry | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ae551c934c4286a321772fb01a21260c36dfccff
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46080318"
---
# <a name="networklinkregistry-class"></a>Classe network_link_registry
O `network_link_registry` gerencia a classe base abstrata os links entre os blocos de origem e destino.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class _Block>
class network_link_registry;
```  
  
#### <a name="parameters"></a>Parâmetros  
*Bloco*<br/>
O bloco tipo de dados estão sendo armazenadas em do `network_link_registry`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`const_pointer`|Um tipo que fornece um ponteiro para um `const` elemento em um `network_link_registry` objeto.|  
|`const_reference`|Um tipo que fornece uma referência a um `const` elemento armazenado em um `network_link_registry` objeto para leitura e execução de operações constantes.|  
|`iterator`|Um tipo que fornece um iterador que pode ler ou modificar qualquer elemento em um `network_link_registry` objeto.|  
|`type`|Um tipo que representa o tipo de bloco armazenado em do `network_link_registry` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[add](#add)|Quando substituído em uma classe derivada, adiciona um link para o `network_link_registry` objeto.|  
|[begin](#begin)|Quando substituído em uma classe derivada, retorna um iterador para o primeiro elemento no `network_link_registry` objeto.|  
|[Contém](#contains)|Quando substituído em uma classe derivada, pesquisa o `network_link_registry` objeto para um bloco especificado.|  
|[count](#count)|Quando substituído em uma classe derivada, retorna o número de itens no `network_link_registry` objeto.|  
|[remove](#remove)|Quando substituído em uma classe derivada, remove um bloco especificado do `network_link_registry` objeto.|  
  
## <a name="remarks"></a>Comentários  
 O `network link registry` não é seguro para o acesso simultâneo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `network_link_registry`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Agents. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="add"></a> Adicionar 

 Quando substituído em uma classe derivada, adiciona um link para o `network_link_registry` objeto.  
  
```
virtual void add(_EType _Link) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
*Link*<br/>
Um ponteiro para um bloco a ser adicionado.  
  
##  <a name="begin"></a> começar 

 Quando substituído em uma classe derivada, retorna um iterador para o primeiro elemento no `network_link_registry` objeto.  
  
```
virtual iterator begin() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que trata o primeiro elemento no `network_link_registry` objeto.  
  
### <a name="remarks"></a>Comentários  
 O estado final do iterador é indicado por um `NULL` link.  
  
##  <a name="contains"></a> Contém 

 Quando substituído em uma classe derivada, pesquisa o `network_link_registry` objeto para um bloco especificado.  
  
```
virtual bool contains(_EType _Link) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
*Link*<br/>
Um ponteiro para um bloco que está sendo procurado no `network_link_registry` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se o bloco foi encontrado, `false` caso contrário.  
  
##  <a name="count"></a> Contagem 

 Quando substituído em uma classe derivada, retorna o número de itens no `network_link_registry` objeto.  
  
```
virtual size_t count() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens no objeto `network_link_registry`.  
  
##  <a name="remove"></a> Remover 

 Quando substituído em uma classe derivada, remove um bloco especificado do `network_link_registry` objeto.  
  
```
virtual bool remove(_EType _Link) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
*Link*<br/>
Um ponteiro para um bloco a ser removido, se encontrado.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se o link foi encontrado e removido, `false` caso contrário.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe single_link_registry](single-link-registry-class.md)   
 [Classe multi_link_registry](multi-link-registry-class.md)
