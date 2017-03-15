---
title: Classe accelerator_view | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- amprt/Concurrency::accelerator_view
dev_langs:
- C++
helpviewer_keywords:
- accelerator_view class
ms.assetid: 9f298c21-bf62-46e0-88b8-01c5c78ef144
caps.latest.revision: 18
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
ms.openlocfilehash: 78569f1ff21af3ed05cb908a851f0fe05d5d271a
ms.lasthandoff: 02/25/2017

---
# <a name="acceleratorview-class"></a>Classe accelerator_view
Representa uma abstração de dispositivo virtual em um acelerador do C++ AMP paralela de dados.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
class accelerator_view;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor accelerator_view](#ctor)|Inicializa uma nova instância da classe `accelerator_view`.|  
|[~ accelerator_view destruidor](#dtor)|Destrói o `accelerator_view` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método create_marker](#create_marker)|Retorna um futuro para controlar a conclusão de todos os comandos enviados até o momento a este `accelerator_view` objeto.|  
|[Método flush](#flush)|Envia todos os comandos pendentes na fila para o `accelerator_view` objeto para o Acelerador de execução.|  
|[Método get_accelerator](#get_accelerator)|Retorna o `accelerator` de objeto para o `accelerator_view` objeto.|  
|[Método get_is_auto_selection](#get_is_auto_selection)|Retorna um valor booliano que indica se o tempo de execução selecionará automaticamente um acelerador apropriado quando o `accelerator_view` objeto é passado para um [parallel_for_each](concurrency-namespace-functions-amp.md#parallel_for_each).|  
|[Método get_is_debug](#get_is_debug)|Retorna um valor booliano que indica se o `accelerator_view` objeto tem a camada de depuração habilitada para o relatório de erros abrangente.|  
|[Método get_queuing_mode](#get_queuing_mode)|Retorna o modo de enfileiramento de mensagens para o `accelerator_view` objeto.|  
|[Método get_version](#get_version)|Retorna a versão do `accelerator_view`.|  
|[Método Wait](#wait)|Aguarda todos os comandos enviados para o `accelerator_view` objeto para concluir.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operador! = operador](#operator_neq)|Compara isso `accelerator_view` objeto com outra e retorna `false` se eles forem iguais; caso contrário, retornará `true`.|  
|[operador Operator =](#operator_eq)|Copia o conteúdo especificado `accelerator_view` deste objeto.|  
|[operador Operator = =](#operator_eq_eq)|Compara isso `accelerator_view` objeto com outra e retorna `true` se eles forem iguais; caso contrário, retornará `false`.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados Accelerator](#accelerator)|Obtém o `accelerator` de objeto para o `accelerator_view` objeto.|  
|[Membro de dados is_auto_selection](#is_auto_selection)|Obtém um valor booliano que indica se o tempo de execução selecionará automaticamente um acelerador apropriado quando o `accelerator_view` objeto é passado para um [parallel_for_each](concurrency-namespace-functions-amp.md#parallel_for_each).|  
|[Membro de dados is_debug](#is_debug)|Obtém um valor booliano que indica se o `accelerator_view` objeto tem a camada de depuração habilitada para o relatório de erros abrangente.|  
|[Membro de dados queuing_mode](#queuing_mode)|Obtém o modo de enfileiramento de mensagens para o `accelerator_view` objeto.|  
|[versão do membro de dados](#version)|Obtém a versão do accelerator.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `accelerator_view`  
  
### <a name="remarks"></a>Comentários  
 Um `accelerator_view` objeto representa uma exibição lógica, isolada de um acelerador. Um dispositivo de computação físico único pode ter muitos lógico, isolado `accelerator_view` objetos. Cada accelerator tem um padrão `accelerator_view` objeto. Adicionais `accelerator_view` objetos podem ser criados.  
  
 Dispositivos físicos podem ser compartilhados entre vários threads de cliente. Threads de cliente podem usar a mesma forma cooperativa `accelerator_view` o objeto de um acelerador ou cada cliente pode se comunicar com um dispositivo de computação por meio de um independente `accelerator_view` objeto para o isolamento de outros threads de cliente.  
  
 Um `accelerator_view` objeto pode ter um dos dois [enumeração queuing_mode](concurrency-namespace-enums-amp.md#queuing_mode) estados. Se o modo de enfileiramento de mensagens é `immediate`, comandos como `copy` e `parallel_for_each` são enviadas para o dispositivo correspondente do acelerador assim que elas retornam ao chamador. Se o modo de enfileiramento de mensagens é `deferred`, esses comandos são colocadas em fila em uma fila de comando que corresponde do `accelerator_view` objeto. Comandos, na verdade, não são enviados para o dispositivo até `flush()` é chamado.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amprt.h  
  
 **Namespace:** Simultaneidade  

## <a name="a-nameacceleratora-accelerator"></a><a name="accelerator"></a>Acelerador 

Obtém o objeto de acelerador para o objeto accelerator_view.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
__declspec(property(get= get_accelerator)) Concurrency::accelerator accelerator;  
```  
  
## <a name="a-namectora-acceleratorview"></a><a name="ctor"></a>accelerator_view 

Inicializa uma nova instância da classe accelerator_view copiando existente `accelerator_view` objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
accelerator_view( const accelerator_view & _Other );  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `accelerator_view` objeto a ser copiado.  
  
## <a name="a-nameacceleratorviewcreatemarkera-createmarker"></a><a name="accelerator_view__create_marker"></a>create_marker 

Retorna um futuro para controlar a conclusão de todos os comandos enviados até o momento a este `accelerator_view` objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
concurrency::completion_future create_marker();  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um futuro para controlar a conclusão de todos os comandos enviados até o momento a este `accelerator_view` objeto.  
  
## <a name="a-nameflusha-flush"></a><a name="flush"></a>liberar 

Envia que todos os comandos pendentes na fila para o objeto accelerator_view para o Acelerador de execução.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void flush();  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `void`.  

## <a name="a-nameacceleratorviewgetacceleratora-getaccelerator"></a><a name="accelerator_view__get_accelerator"></a>get_accelerator 

Retorna o objeto de acelerador para o objeto accelerator_view.
### <a name="syntax"></a>Sintaxe
```
accelerator get_accelerator() const;
```
### <a name="return-value"></a>Valor de retorno
O objeto de acelerador para o objeto accelerator_view.

## <a name="a-nameacceleratorviewgetisautoselectiona-getisautoselection"></a><a name="accelerator_view__get_is_auto_selection"></a>get_is_auto_selection 

Retorna um valor booliano que indica se o tempo de execução selecionará automaticamente um acelerador apropriado quando o accelerator_view é passado para um [parallel_for_each](concurrency-namespace-functions-amp.md#parallel_for_each).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
bool get_is_auto_selection() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o tempo de execução automaticamente selecionará um acelerador apropriado; Caso contrário, `false`.  
  
## <a name="a-nameacceleratorviewgetisdebuga-getisdebug"></a><a name="accelerator_view__get_is_debug"></a>get_is_debug 

Retorna um valor booliano que indica se o objeto accelerator_view tem a camada de depuração habilitada para o relatório de erros abrangente.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
bool get_is_debug() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor booleano que indica se o `accelerator_view` objeto tem a camada de depuração habilitada para o relatório de erros abrangente.  

## <a name="a-nameacceleratorviewgetqueuingmodea-getqueuingmode"></a><a name="accelerator_view__get_queuing_mode"></a>get_queuing_mode 

Retorna o modo de enfileiramento de mensagens para o objeto accelerator_view.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
queuing_mode get_queuing_mode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O modo de enfileiramento de mensagens para o `accelerator_view` objeto.  
  
## <a name="a-nameacceleratorviewgetversiona-getversion"></a><a name="accelerator_view__get_version"></a>get_version 

Retorna a versão dos accelerator_view.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
unsigned int get_version() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A versão do `accelerator_view`.  
  
## <a name="a-nameacceleratorviewisautoselectiona-isautoselection"></a><a name="accelerator_view__is_auto_selection"></a>is_auto_selection 

Obtém um valor booliano que indica se o tempo de execução selecionará automaticamente um acelerador apropriado quando o accelerator_view é passado para um [parallel_for_each](concurrency-namespace-functions-amp.md#parallel_for_each).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
__declspec(property(get= get_is_auto_selection)) bool is_auto_selection;  
```  
  
## <a name="a-nameacceleratorviewisdebuga-isdebug"></a><a name="accelerator_view__is_debug"></a>is_debug 

Obtém um valor booliano que indica se o objeto accelerator_view tem a camada de depuração habilitada para o relatório de erros abrangente.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
__declspec(property(get= get_is_debug)) bool is_debug;  
```  
  
## <a name="a-nameacceleratorviewoperatorneqa-operator"></a><a name="accelerator_view__operator_neq"></a>operador! = 

Compara este objeto accelerator_view com outra e retorna `false` se eles forem iguais; caso contrário, retornará `true`.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
bool operator!= (    const accelerator_view & _Other ) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `accelerator_view` objeto a ser comparado com este.  
  
### <a name="return-value"></a>Valor de retorno  
 `false` se os dois objetos forem iguais; caso contrário, `true`.  
  
## <a name="a-nameacceleratorviewoperatoreqa-operator"></a><a name="accelerator_view__operator_eq"></a>operador = 

Copia o conteúdo do objeto accelerator_view especificado para esta.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
accelerator_view & operator= (    const accelerator_view & _Other );  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `accelerator_view` objeto copiar de.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para a modificação `accelerator_view` objeto.  
  
## <a name="a-nameacceleratorviewoperatoreqeqa-operator"></a><a name="accelerator_view__operator_eq_eq"></a>operador = = 

Compara este objeto accelerator_view com outra e retorna `true` se eles forem iguais; caso contrário, retornará `false`.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
bool operator= = (    const accelerator_view & _Other ) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `accelerator_view` objeto a ser comparado com este.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se os dois objetos forem iguais; caso contrário, `false`.  
  
## <a name="a-nameacceleratorviewqueuingmodea-queuingmode"></a><a name="accelerator_view__queuing_mode"></a>queuing_mode 

Obtém o modo de enfileiramento de mensagens para o objeto accelerator_view.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
__declspec(property(get= get_queuing_mode)) Concurrency::queuing_mode queuing_mode;  
```  
  
## <a name="a-nameacceleratorviewversiona-version"></a><a name="accelerator_view__version"></a>Versão 

Obtém a versão dos accelerator_view.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
__declspec(property(get= get_version)) unsigned int version;  
```  
  
## <a name="a-nameacceleratorviewwaita-wait"></a><a name="accelerator_view__wait"></a>Aguarde 

Aguarda até que todos os comandos enviados para o objeto accelerator_view concluir.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void wait();  
```  
  
#### <a name="return-value"></a>Valor de retorno  
 Retorna `void`.  
  
#### <a name="remarks"></a>Comentários  
 Se o [queuing_mode](concurrency-namespace-enums-amp.md#queuing_mode) é `immediate`, esse método retornará imediatamente sem bloqueio.  
  
##  <a name="a-namedtora-acceleratorview"></a><a name="dtor"></a>~ accelerator_view 

 Destrói o objeto accelerator_view.  
  
#### <a name="syntax"></a>Sintaxe  
  
```  
~accelerator_view();  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
 
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)

