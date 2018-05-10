---
title: 'Namespace Concurrency:: Direct3D | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-amp
ms.topic: reference
f1_keywords:
- amp/Concurrency::direct3d
- amprt/Concurrency::direct3d
- amp_short_vectors/Concurrency::direct3d
- amp_graphics/Concurrency::direct3d
- amp_math/Concurrency::direct3d
dev_langs:
- C++
helpviewer_keywords:
- direct3d namespace
ms.assetid: 9566a2f1-4d5f-43e4-a3ac-676643d38420
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9516e3f89d393405a5f71af569a50e46e381d579
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="concurrencydirect3d-namespace"></a>Namespace Concurrency::direct3d
O `direct3d` namespace fornece funções que oferecem suporte à interoperabilidade D3D. Ele permite o uso contínuo do D3D recursos de computação no código de AMP, bem como permitir o uso de recursos criados em AMP D3D código, sem criar cópias redundantes de intermediárias. Pode acelerar as seções de computação intensiva de seus aplicativos DirectX usando C++ AMP e usar a API do D3D dados produzidos de cálculos AMP incrementalmente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
namespace direct3d;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="classes"></a>Classes  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Classe scoped_d3d_access_lock](scoped-d3d-access-lock-class.md)|Um wrapper RAII para um bloqueio de acesso D3D um `accelerator_view` objeto.|  
  
### <a name="structures"></a>Estruturas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Estrutura adopt_d3d_access_lock_t](adopt-d3d-access-lock-t-structure.md)|Tipo de marca para indicar o bloqueio de acesso do D3D deve ser adotado em vez de adquirido.|  
  
### <a name="functions"></a>Funções  
  
|Nome|Descrição|  
|----------|-----------------|  
|[abs](concurrency-direct3d-namespace-functions-amp.md#abs)|Retorna o valor absoluto do argumento|  
|[clamp](concurrency-direct3d-namespace-functions-amp.md#clamp)|Sobrecarregado. Coloca x para o intervalo especificado de min e máx|  
|[countbits](concurrency-direct3d-namespace-functions-amp.md#countbits)|Conta o número de bits de conjunto em x|  
|[create_accelerator_view](concurrency-direct3d-namespace-functions-amp.md#create_accelerator_view)|Cria um [accelerator_view classe](accelerator-view-class.md) de um ponteiro para uma interface de dispositivo Direct3D|  
|[d3d_access_lock](concurrency-direct3d-namespace-functions-amp.md#d3d_access_lock)|Adquire um bloqueio em um accelerator_view para fins de executar com segurança D3D operações nos recursos compartilhados com o accelerator_view|  
|[d3d_access_try_lock](concurrency-direct3d-namespace-functions-amp.md#d3d_access_try_lock)|Tentativa de adquirir o bloqueio de acesso do D3D em um accelerator_view sem bloqueio.|  
|[d3d_access_unlock](concurrency-direct3d-namespace-functions-amp.md#d3d_access_unlock)|Libere o bloqueio de acesso D3D o accelerator_view determinado.|  
|[firstbithigh](concurrency-direct3d-namespace-functions-amp.md#firstbithigh)|Obtém o local do primeiro conjunto de bit em x, começando a partir do bit de ordem mais alto e trabalhando para baixo|  
|[firstbitlow](concurrency-direct3d-namespace-functions-amp.md#firstbitlow)|Obtém o local do primeiro conjunto de bit em x, começando a partir do bit de ordem mais baixo e trabalhando para cima|  
|[get_buffer](concurrency-direct3d-namespace-functions-amp.md#get_buffer)|Obter a interface de buffer D3D subjacente de uma matriz.|  
|[imax](concurrency-direct3d-namespace-functions-amp.md#imax)|Compara dois valores, retornando o valor que for maior.|  
|[imin](concurrency-direct3d-namespace-functions-amp.md#imin)|Compara dois valores, retornando o valor que é menor.|  
|[is_timeout_disabled](concurrency-direct3d-namespace-functions-amp.md#is_timeout_disabled)|Retorna um sinalizador booliano que indica se o tempo limite está desabilitado para o accelerator_view especificado.|  
|[mad](concurrency-direct3d-namespace-functions-amp.md#mad)|Sobrecarregado. Executa uma operação aritmética multiplicar ou adicionar em três argumentos: x * y + z|  
|[make_array](concurrency-direct3d-namespace-functions-amp.md#make_array)|Crie uma matriz de um ponteiro de interface de buffer D3D.|  
|[noise](concurrency-direct3d-namespace-functions-amp.md#noise)|Gera um valor aleatório usando o algoritmo de ruído Perlin|  
|[radianos](concurrency-direct3d-namespace-functions-amp.md#radians)|Converte x de graus em radianos|  
|[rcp](concurrency-direct3d-namespace-functions-amp.md#rcp)|Calcula um recíproco rápido, aproximado do argumento|  
|[reversebits](concurrency-direct3d-namespace-functions-amp.md#reversebits)|Inverte a ordem dos bits em x|  
|[saturate](concurrency-direct3d-namespace-functions-amp.md#saturate)|Coloca x dentro do intervalo de 0 a 1|  
|[sign](concurrency-direct3d-namespace-functions-amp.md#sign)|Sobrecarregado. Retorna o sinal do argumento|  
|[smoothstep](concurrency-direct3d-namespace-functions-amp.md#smoothstep)|Retorna uma interpolação Hermite suave entre 0 e 1, se x está no intervalo [ min, máx].|  
|[step](concurrency-direct3d-namespace-functions-amp.md#step)|Compara dois valores, retornando 0 ou 1 com base em qual valor é maior|  
|[umax](concurrency-direct3d-namespace-functions-amp.md#umax)|Compara dois valores não assinados, retornando o valor que for maior.|  
|[umin](concurrency-direct3d-namespace-functions-amp.md#umin)|Compara dois valores não assinados, retornando o valor que é menor.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp.h  
  
 **Namespace:** Simultaneidade  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
