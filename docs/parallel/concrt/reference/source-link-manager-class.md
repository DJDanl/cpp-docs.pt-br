---
title: Classe source_link_manager | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- agents/concurrency::source_link_manager
dev_langs:
- C++
helpviewer_keywords:
- source_link_manager class
ms.assetid: 287487cf-e0fe-4c35-aa3c-24f081d1ddae
caps.latest.revision: 17
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
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: b9323da4d2ccefe09ba38df088e546828d41f2ee
ms.lasthandoff: 02/25/2017

---
# <a name="sourcelinkmanager-class"></a>Classe source_link_manager
O `source_link_manager` objeto gerencia conexões de rede bloquear mensagens com `ISource` blocos.  
  
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
|`const_pointer`|Um tipo que fornece um ponteiro para um `const` elemento em uma `source_link_manager` objeto.|  
|`const_reference`|Um tipo que fornece uma referência a um `const` elemento armazenado em uma `source_link_manager` objeto para ler e executar operações constantes.|  
|`iterator`|Um tipo que fornece um iterador que pode ler ou modificar qualquer elemento de `source_link_manager` objeto.|  
|`type`|O tipo de registro de link que está sendo gerenciado pelo `source_link_manager` objeto.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor source_link_manager](#ctor)|Constrói um objeto `source_link_manager`.|  
|[~ source_link_manager destruidor](#dtor)|Destrói o `source_link_manager` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[o método Add](#add)|Adiciona um link de origem para o `source_link_manager` objeto.|  
|[Método Begin](#begin)|Retorna um iterador para o primeiro elemento no `source_link_manager` objeto.|  
|[Método Contains](#contains)|Pesquisas de `network_link_registry` dentro dessa `source_link_manager` objeto para um bloco especificado.|  
|[Método Count](#count)|Conta o número de blocos de vinculado a `source_link_manager` objeto.|  
|[referência de método](#reference)|Adquire uma referência sobre o `source_link_manager` objeto.|  
|[Método register_target_block](#register_target_block)|Registra o bloco de destino que contém esse `source_link_manager` objeto.|  
|[Método de liberação](#release)|Libera a referência sobre o `source_link_manager` objeto.|  
|[Método Remove](#remove)|Remove um link do `source_link_manager` objeto.|  
|[Método set_bound](#set_bound)|Define o número máximo de links de origem que podem ser adicionados a este `source_link_manager` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Atualmente, os blocos de código-fonte são contados como referência. Este é um wrapper em uma `network_link_registry` objeto que permite o acesso simultâneo aos links e fornece a capacidade de fazer referência os links por meio de retornos de chamada. Blocos de mensagens ( `target_block`s ou `propagator_block`s) deve usar essa classe para seus links de origem.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `source_link_manager`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-nameadda-add"></a><a name="add"></a>Adicionar 

 Adiciona um link de origem para o `source_link_manager` objeto.  
  
```
void add(_EType _Link);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Link`  
 Um ponteiro para um bloco a ser adicionado.  
  
##  <a name="a-namebegina-begin"></a><a name="begin"></a>começar 

 Retorna um iterador para o primeiro elemento no `source_link_manager` objeto.  
  
```
iterator begin();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que trata o primeiro elemento no `source_link_manager` objeto.  
  
### <a name="remarks"></a>Comentários  
 O estado final do iterador é indicado por um `NULL` link.  
  
##  <a name="a-namecontainsa-contains"></a><a name="contains"></a>contém 

 Pesquisas de `network_link_registry` dentro dessa `source_link_manager` objeto para um bloco especificado.  
  
```
bool contains(_EType _Link);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Link`  
 Um ponteiro para um bloco que deve ser procurado no `source_link_manager` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o bloco especificado foi encontrado, `false` caso contrário.  
  
##  <a name="a-namecounta-count"></a><a name="count"></a>Contagem 

 Conta o número de blocos de vinculado a `source_link_manager` objeto.  
  
```
size_t count();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de blocos de vinculado a `source_link_manager` objeto.  
  
##  <a name="a-namereferencea-reference"></a><a name="reference"></a>referência 

 Adquire uma referência sobre o `source_link_manager` objeto.  
  
```
void reference();
```  
  
##  <a name="a-nameregistertargetblocka-registertargetblock"></a><a name="register_target_block"></a>register_target_block 

 Registra o bloco de destino que contém esse `source_link_manager` objeto.  
  
```
void register_target_block(_Inout_ ITarget<typename _Block::source_type>* _PTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PTarget`  
 O bloco de destino mantém esse `source_link_manager` objeto.  
  
##  <a name="a-namereleasea-release"></a><a name="release"></a>versão 

 Libera a referência sobre o `source_link_manager` objeto.  
  
```
void release();
```  
  
##  <a name="a-nameremovea-remove"></a><a name="remove"></a>Remover 

 Remove um link do `source_link_manager` objeto.  
  
```
bool remove(_EType _Link);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Link`  
 Um ponteiro para um bloco a ser removido, se encontrado.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o link foi encontrado e removido, `false` caso contrário.  
  
##  <a name="a-namesetbounda-setbound"></a><a name="set_bound"></a>set_bound 

 Define o número máximo de links de origem que podem ser adicionados a este `source_link_manager` objeto.  
  
```
void set_bound(size_t _MaxLinks);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MaxLinks`  
 O número máximo de links.  
  
##  <a name="a-namectora-sourcelinkmanager"></a><a name="ctor"></a>source_link_manager 

 Constrói um objeto `source_link_manager`.  
  
```
source_link_manager();
```  
  
##  <a name="a-namedtora-sourcelinkmanager"></a><a name="dtor"></a>~ source_link_manager 

 Destrói o `source_link_manager` objeto.  
  
```
~source_link_manager();
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe single_link_registry](single-link-registry-class.md)   
 [Classe multi_link_registry](multi-link-registry-class.md)

