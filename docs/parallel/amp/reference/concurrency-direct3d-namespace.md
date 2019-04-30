---
title: Namespace Concurrency::direct3d
ms.date: 11/04/2016
f1_keywords:
- amp/Concurrency::direct3d
- amprt/Concurrency::direct3d
- amp_short_vectors/Concurrency::direct3d
- amp_graphics/Concurrency::direct3d
- amp_math/Concurrency::direct3d
helpviewer_keywords:
- direct3d namespace
ms.assetid: 9566a2f1-4d5f-43e4-a3ac-676643d38420
ms.openlocfilehash: 6afbd7b3a3f4280ad658c1cb9d8802cc3251d0ed
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62405476"
---
# <a name="concurrencydirect3d-namespace"></a>Namespace Concurrency::direct3d

O `direct3d` namespace fornece funções que suportam a interoperabilidade D3D. Ele permite o uso contínuo de recursos de D3D para cálculos no código AMP bem como permitir o uso de recursos criados no AMP no código D3D, sem criar cópias intermediárias redundantes. Incrementalmente, você pode acelerar as seções intensas de cálculo dos seus aplicativos DirectX usando o C++ AMP e usar o D3D API em dados gerados pelos cálculos AMP.

## <a name="syntax"></a>Sintaxe

```
namespace direct3d;
```

## <a name="members"></a>Membros

### <a name="classes"></a>Classes

|Nome|Descrição|
|----------|-----------------|
|[Classe scoped_d3d_access_lock](scoped-d3d-access-lock-class.md)|Um wrapper RAII para um bloqueio de acesso de D3D em um `accelerator_view` objeto.|

### <a name="structures"></a>Estruturas

|Nome|Descrição|
|----------|-----------------|
|[Estrutura adopt_d3d_access_lock_t](adopt-d3d-access-lock-t-structure.md)|Tipo de marca para indicar o bloqueio de acesso de D3D deve ser adotado em vez de adquirida.|

### <a name="functions"></a>Funções

|Nome|Descrição|
|----------|-----------------|
|[abs](concurrency-direct3d-namespace-functions-amp.md#abs)|Retorna o valor absoluto do argumento|
|[clamp](concurrency-direct3d-namespace-functions-amp.md#clamp)|Sobrecarregado. Aperta o x para o intervalo especificado min e Max|
|[countbits](concurrency-direct3d-namespace-functions-amp.md#countbits)|Conta o número de bits definidos em x|
|[create_accelerator_view](concurrency-direct3d-namespace-functions-amp.md#create_accelerator_view)|Cria uma [classe accelerator_view](accelerator-view-class.md) de um ponteiro para uma interface de dispositivo Direct3D|
|[d3d_access_lock](concurrency-direct3d-namespace-functions-amp.md#d3d_access_lock)|Adquire um bloqueio em um accelerator_view com a finalidade de executar operações de D3D em recursos compartilhados com o accelerator_view de forma segura|
|[d3d_access_try_lock](concurrency-direct3d-namespace-functions-amp.md#d3d_access_try_lock)|Tentativa de adquirir o bloqueio de acesso de D3D em um accelerator_view sem bloqueio.|
|[d3d_access_unlock](concurrency-direct3d-namespace-functions-amp.md#d3d_access_unlock)|Libere o bloqueio de acesso de D3D no accelerator_view determinado.|
|[firstbithigh](concurrency-direct3d-namespace-functions-amp.md#firstbithigh)|Obtém o local do primeiro bit definido em x, começando a partir do bit de ordem mais alto e descendo|
|[firstbitlow](concurrency-direct3d-namespace-functions-amp.md#firstbitlow)|Obtém o local do primeiro bit definido em x, começando a partir do bit de ordem mais baixo e trabalhando para cima|
|[get_buffer](concurrency-direct3d-namespace-functions-amp.md#get_buffer)|Obtenha a interface do buffer D3D subjacente a uma matriz.|
|[imax](concurrency-direct3d-namespace-functions-amp.md#imax)|Compara dois valores, retornando o valor que for maior.|
|[imin](concurrency-direct3d-namespace-functions-amp.md#imin)|Compara dois valores, retornando o valor que for menor.|
|[is_timeout_disabled](concurrency-direct3d-namespace-functions-amp.md#is_timeout_disabled)|Retorna um sinalizador booliano que indica se o tempo limite está desativado para o accelerator_view especificado.|
|[mad](concurrency-direct3d-namespace-functions-amp.md#mad)|Sobrecarregado. Executa uma operação aritmética multiplicação/adição em três argumentos: x \* y + z|
|[make_array](concurrency-direct3d-namespace-functions-amp.md#make_array)|Crie uma matriz de um ponteiro de interface do buffer D3D.|
|[noise](concurrency-direct3d-namespace-functions-amp.md#noise)|Gera um valor aleatório usando o algoritmo de ruído de Perlin|
|[radians](concurrency-direct3d-namespace-functions-amp.md#radians)|Converte x de graus em radianos|
|[rcp](concurrency-direct3d-namespace-functions-amp.md#rcp)|Calcula um recíproco rápido e aproximado do argumento|
|[reversebits](concurrency-direct3d-namespace-functions-amp.md#reversebits)|Inverte a ordem dos bits em x|
|[saturate](concurrency-direct3d-namespace-functions-amp.md#saturate)|Aperta o x dentro do intervalo de 0 a 1|
|[sign](concurrency-direct3d-namespace-functions-amp.md#sign)|Sobrecarregado. Retorna o sinal do argumento|
|[smoothstep](concurrency-direct3d-namespace-functions-amp.md#smoothstep)|Retorna uma interpolação suave de Hermite entre 0 e 1, se x está no intervalo [ min, Max].|
|[step](concurrency-direct3d-namespace-functions-amp.md#step)|Compara dois valores, retornando 0 ou 1, com base em qual valor é maior|
|[umax](concurrency-direct3d-namespace-functions-amp.md#umax)|Compara dois valores não assinados, retornando o valor que for maior.|
|[umin](concurrency-direct3d-namespace-functions-amp.md#umin)|Compara dois valores não assinados, retornando o valor que for menor.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp. h

**Namespace:** Concorrência

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
