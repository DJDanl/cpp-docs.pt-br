---
title: Classe multi_link_registry | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- multi_link_registry
- AGENTS/concurrency::multi_link_registry
- AGENTS/concurrency::multi_link_registry::multi_link_registry
- AGENTS/concurrency::multi_link_registry::add
- AGENTS/concurrency::multi_link_registry::begin
- AGENTS/concurrency::multi_link_registry::contains
- AGENTS/concurrency::multi_link_registry::count
- AGENTS/concurrency::multi_link_registry::remove
- AGENTS/concurrency::multi_link_registry::set_bound
dev_langs:
- C++
helpviewer_keywords:
- multi_link_registry class
ms.assetid: b2aa73a8-e8a6-4255-b117-d07530c328b2
caps.latest.revision: 19
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
ms.openlocfilehash: b52ee20ed16a4ce8d0b9f11b6acf25112464b49b
ms.lasthandoff: 03/17/2017

---
# <a name="multilinkregistry-class"></a>Classe multi_link_registry
O `multi_link_registry` objeto é um `network_link_registry` que gerencia vários blocos de código-fonte ou vários blocos de destino.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class _Block>
class multi_link_registry : public network_link_registry<_Block>;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_Block`  
 O bloco tipo de dados que estão sendo armazenados no `multi_link_registry` objeto.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[multi_link_registry](#ctor)|Constrói um objeto `multi_link_registry`.|  
|[~ multi_link_registry destruidor](#dtor)|Destrói o `multi_link_registry` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[add](#add)|Adiciona um link para o `multi_link_registry` objeto. (Substitui [network_link_registry:: Add](network-link-registry-class.md#add).)|  
|[begin](#begin)|Retorna um iterador para o primeiro elemento no `multi_link_registry` objeto. (Substitui [network_link_registry:: Begin](network-link-registry-class.md#begin).)|  
|[contém](#contains)|Pesquisas de `multi_link_registry` objeto para um bloco especificado. (Substitui [network_link_registry:: Contains](network-link-registry-class.md#contains).)|  
|[count](#count)|Conta o número de itens de `multi_link_registry` objeto. (Substitui [network_link_registry:: Count](network-link-registry-class.md#count).)|  
|[remove](#remove)|Remove um link do `multi_link_registry` objeto. (Substitui [network_link_registry:: remove](network-link-registry-class.md#remove).)|  
|[set_bound](#set_bound)|Define um limite superior no número de links de `multi_link_registry` objeto pode conter.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [network_link_registry](network-link-registry-class.md)  
  
 `multi_link_registry`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="add"></a>Adicionar 

 Adiciona um link para o `multi_link_registry` objeto.  
  
```
virtual void add(_EType _Link);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Link`  
 Um ponteiro para um bloco a ser adicionado.  
  
### <a name="remarks"></a>Comentários  
 O método lança um [invalid_link_target](invalid-link-target-class.md) exceção se o link já está presente no registro, ou se um limite já foi definida com o `set_bound` função e um link já foi removido.  
  
##  <a name="begin"></a>começar 

 Retorna um iterador para o primeiro elemento no `multi_link_registry` objeto.  
  
```
virtual iterator begin();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que trata o primeiro elemento no `multi_link_registry` objeto.  
  
### <a name="remarks"></a>Comentários  
 O estado final é indicado por um `NULL` link.  
  
##  <a name="contains"></a>contém 

 Pesquisas de `multi_link_registry` objeto para um bloco especificado.  
  
```
virtual bool contains(_EType _Link);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Link`  
 Um ponteiro para um bloco que deve ser procurado no `multi_link_registry` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o bloco especificado foi encontrado, `false` caso contrário.  
  
##  <a name="count"></a>Contagem 

 Conta o número de itens de `multi_link_registry` objeto.  
  
```
virtual size_t count();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens no objeto `multi_link_registry`.  
  
##  <a name="ctor"></a>multi_link_registry 

 Constrói um objeto `multi_link_registry`.  
  
```
multi_link_registry();
```  
  
##  <a name="dtor"></a>~ multi_link_registry 

 Destrói o `multi_link_registry` objeto.  
  
```
virtual ~multi_link_registry();
```  
  
### <a name="remarks"></a>Comentários  
 O método lança um [invalid_operation](invalid-operation-class.md) exceção se chamada antes que todos os links são removidos.  
  
##  <a name="remove"></a>Remover 

 Remove um link do `multi_link_registry` objeto.  
  
```
virtual bool remove(_EType _Link);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Link`  
 Um ponteiro para um bloco a ser removido, se encontrado.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o link foi encontrado e removido, `false` caso contrário.  
  
##  <a name="set_bound"></a>set_bound 

 Define um limite superior no número de links de `multi_link_registry` objeto pode conter.  
  
```
void set_bound(size_t _MaxLinks);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MaxLinks`  
 O número máximo de links que o `multi_link_registry` objeto pode conter.  
  
### <a name="remarks"></a>Comentários  
 Após definir um limite, desvincular uma entrada fará com que o `multi_link_registry` objeto entrar em um estado imutável onde nenhuma chamada para `add` lançará um `invalid_link_target` exceção.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe single_link_registry](single-link-registry-class.md)

