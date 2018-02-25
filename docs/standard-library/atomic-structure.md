---
title: "Estrutura atômica | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- atomic/std::atomic
dev_langs:
- C++
ms.assetid: 261628ed-7049-41ac-99b9-cfe49f696b44
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e5e7de7a5098aec10618c961444eb73b4597d0fc
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="atomic-structure"></a>Estrutura atomic
Descreve um objeto que executa operações atômicas em um valor armazenado do tipo `Ty`.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Ty>
struct atomic;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[atomic](http://msdn.microsoft.com/Library/a538c43f-4d48-4308-ae1b-bab1839bccb8)|Constrói um objeto atômico.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador atomic::operator Ty](http://msdn.microsoft.com/Library/a366c700-c7a0-4bcb-8eb4-4b57dfaea065)|Lê e retorna o valor armazenado. ([atomic::load](http://msdn.microsoft.com/Library/05212726-cf8a-46fe-83d2-c16ac2abb7d1))|  
|[Operador atomic::operator=](http://msdn.microsoft.com/Library/fe161d57-47ae-4bad-92bf-ce32ac8d5953)|Usa um valor especificado para substituir o valor armazenado. ([atomic::store](http://msdn.microsoft.com/Library/84759413-d664-47ef-a1f3-a73c5a62007b))|  
|[Operador atomic::operator++](http://msdn.microsoft.com/Library/492959e9-1ea8-4e02-a031-82b1b92e91a0)|Incrementa o valor armazenado. Usado somente por especializações integrais e de ponteiro.|  
|[Operador atomic::operator+=](http://msdn.microsoft.com/Library/9ec97aa2-c9d7-436b-943d-2989eb2617dd)|Adiciona um valor especificado ao valor armazenado. Usado somente por especializações integrais e de ponteiro.|  
|[Operador atomic::operator--](http://msdn.microsoft.com/Library/ad7c1ea7-1f6d-4a54-bf26-07630f749864)|Decrementa o valor armazenado. Usado somente por especializações integrais e de ponteiro.|  
|[Operador atomic::operator-=](http://msdn.microsoft.com/Library/902d0d9f-88fd-4500-aa2d-1e50f443e77c)|Subtrai um valor especificado do valor armazenado. Usado somente por especializações integrais e de ponteiro.|  
|[Operador atomic::operator&=](http://msdn.microsoft.com/Library/90e730ac-12e1-4abb-98f5-4eadd6861a89)|Executa um `and` bit a bit em um valor especificado e no valor armazenado. Usado somente por especializações integrais.|  
|[Operador atomic::operator&#124;=](http://msdn.microsoft.com/Library/f105eacc-31a6-4906-abba-f1cf013599b2)|Executa um `or` bit a bit em um valor especificado e no valor armazenado. Usado somente por especializações integrais.|  
|[Operador atomic::operator^=](http://msdn.microsoft.com/Library/f2a4da9d-67e8-4249-9161-9998e72a33c2)|Executa um `exclusive or` bit a bit em um valor especificado e no valor armazenado. Usado somente por especializações integrais.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[compare_exchange_strong](http://msdn.microsoft.com/Library/47bbf894-b28c-4ece-959e-67b3863cf4ed)|Executa uma operação `atomic_compare_and_exchange` em `this` e retorna o resultado.|  
|[compare_exchange_weak](http://msdn.microsoft.com/Library/e15e421a-f7a3-4272-993a-f487d2242e4f)|Executa uma operação `weak_atomic_compare_and_exchange` em `this` e retorna o resultado.|  
|[fetch_add](http://msdn.microsoft.com/Library/c68b91f2-6e8a-4ffa-8991-6bb6d466e1f3)|Adiciona um valor especificado ao valor armazenado.|  
|[fetch_and](http://msdn.microsoft.com/Library/a9c83001-b72c-4085-9640-f63f866714b9)|Executa um `and` bit a bit em um valor especificado e no valor armazenado.|  
|[fetch_or](http://msdn.microsoft.com/Library/4c532f7f-80c5-432a-b34b-48feacab8dca)|Executa um `or` bit a bit em um valor especificado e no valor armazenado.|  
|[fetch_sub](http://msdn.microsoft.com/Library/8cc80d4b-0942-45a3-9db8-bbf339a903e4)|Subtrai um valor especificado do valor armazenado.|  
|[fetch_xor](http://msdn.microsoft.com/Library/92bbaff8-ee29-4a1e-aee4-d9d405285bfe)|Executa um `exclusive or` bit a bit em um valor especificado e no valor armazenado.|  
|[is_lock_free](http://msdn.microsoft.com/Library/b99d5130-cdda-40a2-b14c-152b13a8ba45)|Especifica se operações atômicas em um `this` são *livres de bloqueio*. Um tipo atômico é *livre de bloqueio* se nenhuma operação atômica no tipo usar bloqueios.|  
|[load](http://msdn.microsoft.com/Library/05212726-cf8a-46fe-83d2-c16ac2abb7d1)|Lê e retorna o valor armazenado.|  
|[repositório](http://msdn.microsoft.com/Library/84759413-d664-47ef-a1f3-a73c5a62007b)|Usa um valor especificado para substituir o valor armazenado.|  
  
## <a name="remarks"></a>Comentários  
 O tipo `Ty` deve ser *facilmente copiado*. Ou seja, usar [memcpy](../c-runtime-library/reference/memcpy-wmemcpy.md) para copiar seus bytes deve produzir um objeto `Ty` válido comparável ao objeto original. As funções membro `compare_exchange_weak` e `compare_exchange_strong` usam [memcmp](../c-runtime-library/reference/memcmp-wmemcmp.md) para determinar se dois valores `Ty` são iguais. Essas funções não usarão um `operator==` definido por `Ty`. As funções membro de `atomic` usam `memcpy` para copiar valores do tipo `Ty`.  
  
 Uma especialização parcial, `atomic<Ty *>`, existe para todos os tipos de ponteiro. A especialização permite a adição de um deslocamento para o valor do ponteiro gerenciado ou subtração de um deslocamento dele. Operações aritméticas obtêm um argumento do tipo `ptrdiff_t` e ajustam esse argumento de acordo com o tamanho de `Ty` para serem consistentes com endereço comum aritmético.  
  
 Existe uma especialização para cada tipo integral, exceto `bool`. Cada especialização fornece um rico conjunto de métodos para operações aritméticas e lógicas atômicas.  
  
||||  
|-|-|-|  
|`atomic<char>`|`atomic<signed char>`|`atomic<unsigned char>`|  
|`atomic<char16_t>`|`atomic<char32_t>`|`atomic<wchar_t>`|  
|`atomic<short>`|`atomic<unsigned short>`|`atomic<int>`|  
|`atomic<unsigned int>`|`atomic<long>`|`atomic<unsigned long>`|  
|`atomic<long long>`|`atomic<unsigned long long>`|  
  
 Especializações integrais são derivadas de tipos `atomic_integral` correspondentes. Por exemplo, `atomic<unsigned int>` é derivado de `atomic_uint`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<atômico >  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [\<atomic>](../standard-library/atomic.md)   
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)



