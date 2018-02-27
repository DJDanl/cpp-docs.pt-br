---
title: Classe source_link_manager | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- source_link_manager
- AGENTS/concurrency::source_link_manager
- AGENTS/concurrency::source_link_manager::source_link_manager
- AGENTS/concurrency::source_link_manager::add
- AGENTS/concurrency::source_link_manager::begin
- AGENTS/concurrency::source_link_manager::contains
- AGENTS/concurrency::source_link_manager::count
- AGENTS/concurrency::source_link_manager::reference
- AGENTS/concurrency::source_link_manager::register_target_block
- AGENTS/concurrency::source_link_manager::release
- AGENTS/concurrency::source_link_manager::remove
- AGENTS/concurrency::source_link_manager::set_bound
dev_langs:
- C++
helpviewer_keywords:
- source_link_manager class
ms.assetid: 287487cf-e0fe-4c35-aa3c-24f081d1ddae
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f6368511a7e824e6e1bb69542815fce1e864a964
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="sourcelinkmanager-class"></a>Classe source_link_manager
O `source_link_manager` objeto gerencia mensagens links de rede de bloco para `ISource` blocos.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class _LinkRegistry>
class source_link_manager;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_LinkRegistry`  
 O registro de link de rede.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`const_pointer`|Um tipo que fornece um ponteiro para um `const` elemento em um `source_link_manager` objeto.|  
|`const_reference`|Um tipo que fornece uma referência a um `const` elemento armazenado em uma `source_link_manager` objeto para ler e executar operações constantes.|  
|`iterator`|Um tipo que fornece um iterador que pode ler ou modificar qualquer elemento a `source_link_manager` objeto.|  
|`type`|O tipo de registro de link que está sendo gerenciado pelo `source_link_manager` objeto.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[source_link_manager](#ctor)|Constrói um objeto `source_link_manager`.|  
|[~ source_link_manager destruidor](#dtor)|Destrói a `source_link_manager` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[add](#add)|Adiciona um link de origem para o `source_link_manager` objeto.|  
|[begin](#begin)|Retorna um iterador para o primeiro elemento no `source_link_manager` objeto.|  
|[contains](#contains)|Pesquisas de `network_link_registry` dentro deste `source_link_manager` objeto para um bloco especificado.|  
|[count](#count)|Conta o número de blocos vinculados a `source_link_manager` objeto.|  
|[reference](#reference)|Adquire uma referência sobre o `source_link_manager` objeto.|  
|[register_target_block](#register_target_block)|Registra o bloco de destino que contém este `source_link_manager` objeto.|  
|[release](#release)|Libera a referência sobre o `source_link_manager` objeto.|  
|[remove](#remove)|Remove um link entre a `source_link_manager` objeto.|  
|[set_bound](#set_bound)|Define o número máximo de links de origem que podem ser adicionados a este `source_link_manager` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Atualmente, os blocos de código-fonte são contados como referência. Este é um wrapper em uma `network_link_registry` objeto que permite o acesso simultâneo a links e fornece a capacidade de referenciar os links por meio de retornos de chamada. Blocos de mensagens ( `target_block`s ou `propagator_block`s) deve usar essa classe para seus links de origem.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `source_link_manager`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="add"></a> Adicionar 

 Adiciona um link de origem para o `source_link_manager` objeto.  
  
```
void add(_EType _Link);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Link`  
 Um ponteiro para um bloco a ser adicionado.  
  
##  <a name="begin"></a> Começar 

 Retorna um iterador para o primeiro elemento no `source_link_manager` objeto.  
  
```
iterator begin();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de endereçamento do primeiro elemento no `source_link_manager` objeto.  
  
### <a name="remarks"></a>Comentários  
 O estado final do iterador é indicado por um `NULL` link.  
  
##  <a name="contains"></a> Contém 

 Pesquisas de `network_link_registry` dentro deste `source_link_manager` objeto para um bloco especificado.  
  
```
bool contains(_EType _Link);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Link`  
 Um ponteiro para um bloco a ser procurado no `source_link_manager` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se o bloco especificado for encontrado, `false` caso contrário.  
  
##  <a name="count"></a> Contagem 

 Conta o número de blocos vinculados a `source_link_manager` objeto.  
  
```
size_t count();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de blocos vinculados a `source_link_manager` objeto.  
  
##  <a name="reference"></a> Referência 

 Adquire uma referência sobre o `source_link_manager` objeto.  
  
```
void reference();
```  
  
##  <a name="register_target_block"></a> register_target_block 

 Registra o bloco de destino que contém este `source_link_manager` objeto.  
  
```
void register_target_block(_Inout_ ITarget<typename _Block::source_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 O bloco de destino mantendo isso `source_link_manager` objeto.  
  
##  <a name="release"></a> versão 

 Libera a referência sobre o `source_link_manager` objeto.  
  
```
void release();
```  
  
##  <a name="remove"></a> Remover 

 Remove um link entre a `source_link_manager` objeto.  
  
```
bool remove(_EType _Link);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Link`  
 Um ponteiro para um bloco a ser removido, se encontrado.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se o link foi encontrado e removido, `false` caso contrário.  
  
##  <a name="set_bound"></a> set_bound 

 Define o número máximo de links de origem que podem ser adicionados a este `source_link_manager` objeto.  
  
```
void set_bound(size_t _MaxLinks);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MaxLinks`  
 O número máximo de links.  
  
##  <a name="ctor"></a> source_link_manager 

 Constrói um objeto `source_link_manager`.  
  
```
source_link_manager();
```  
  
##  <a name="dtor"></a> ~ source_link_manager 

 Destrói a `source_link_manager` objeto.  
  
```
~source_link_manager();
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe single_link_registry](single-link-registry-class.md)   
 [Classe multi_link_registry](multi-link-registry-class.md)
