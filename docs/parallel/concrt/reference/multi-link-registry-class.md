---
title: Classe multi_link_registry | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5fbe52298f267fabb2ba326e3e1c7b66f4ad49ef
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33688928"
---
# <a name="multilinkregistry-class"></a>Classe multi_link_registry
O `multi_link_registry` objeto é um `network_link_registry` que gerencia vários blocos de origem ou de vários blocos de destino.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class _Block>
class multi_link_registry : public network_link_registry<_Block>;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_Block`  
 O bloco tipo de dados que estão sendo armazenados no `multi_link_registry` objeto.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[multi_link_registry](#ctor)|Constrói um objeto `multi_link_registry`.|  
|[~ multi_link_registry destruidor](#dtor)|Destrói a `multi_link_registry` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[add](#add)|Adiciona um link para o `multi_link_registry` objeto. (Substitui [network_link_registry:: Add](network-link-registry-class.md#add).)|  
|[begin](#begin)|Retorna um iterador para o primeiro elemento no `multi_link_registry` objeto. (Substitui [network_link_registry:: Begin](network-link-registry-class.md#begin).)|  
|[Contém](#contains)|Pesquisas de `multi_link_registry` objeto para um bloco especificado. (Substitui [network_link_registry:: Contains](network-link-registry-class.md#contains).)|  
|[count](#count)|Conta o número de itens de `multi_link_registry` objeto. (Substitui [network_link_registry:: Count](network-link-registry-class.md#count).)|  
|[remove](#remove)|Remove um link entre a `multi_link_registry` objeto. (Substitui [network_link_registry:: remove](network-link-registry-class.md#remove).)|  
|[set_bound](#set_bound)|Define um limite superior no número de links de `multi_link_registry` objeto pode conter.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [network_link_registry](network-link-registry-class.md)  
  
 `multi_link_registry`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="add"></a> Adicionar 

 Adiciona um link para o `multi_link_registry` objeto.  
  
```
virtual void add(_EType _Link);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Link`  
 Um ponteiro para um bloco a ser adicionado.  
  
### <a name="remarks"></a>Comentários  
 O método gera uma [invalid_link_target](invalid-link-target-class.md) exceção se o link já está presente no registro, ou se uma associação já foi definida com o `set_bound` função e um link já foi removido.  
  
##  <a name="begin"></a> Começar 

 Retorna um iterador para o primeiro elemento no `multi_link_registry` objeto.  
  
```
virtual iterator begin();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de endereçamento do primeiro elemento no `multi_link_registry` objeto.  
  
### <a name="remarks"></a>Comentários  
 O estado final é indicado por um `NULL` link.  
  
##  <a name="contains"></a> Contém 

 Pesquisas de `multi_link_registry` objeto para um bloco especificado.  
  
```
virtual bool contains(_EType _Link);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Link`  
 Um ponteiro para um bloco a ser procurado no `multi_link_registry` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se o bloco especificado for encontrado, `false` caso contrário.  
  
##  <a name="count"></a> Contagem 

 Conta o número de itens de `multi_link_registry` objeto.  
  
```
virtual size_t count();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens no objeto `multi_link_registry`.  
  
##  <a name="ctor"></a> multi_link_registry 

 Constrói um objeto `multi_link_registry`.  
  
```
multi_link_registry();
```  
  
##  <a name="dtor"></a> ~ multi_link_registry 

 Destrói a `multi_link_registry` objeto.  
  
```
virtual ~multi_link_registry();
```  
  
### <a name="remarks"></a>Comentários  
 O método gera uma [invalid_operation](invalid-operation-class.md) exceção se for chamado antes de todos os links são removidos.  
  
##  <a name="remove"></a> Remover 

 Remove um link entre a `multi_link_registry` objeto.  
  
```
virtual bool remove(_EType _Link);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Link`  
 Um ponteiro para um bloco a ser removido, se encontrado.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se o link foi encontrado e removido, `false` caso contrário.  
  
##  <a name="set_bound"></a> set_bound 

 Define um limite superior no número de links de `multi_link_registry` objeto pode conter.  
  
```
void set_bound(size_t _MaxLinks);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MaxLinks`  
 O número máximo de links que o `multi_link_registry` objeto pode conter.  
  
### <a name="remarks"></a>Comentários  
 Após definir um limite, uma entrada ao desvincular fará com que o `multi_link_registry` objeto entrar em um estado imutável onde nenhuma chamada para `add` lançará um `invalid_link_target` exceção.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe single_link_registry](single-link-registry-class.md)
