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
ms.openlocfilehash: e1374acbd7061afaba372100cf6e69d9d717da8a
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77127027"
---
# <a name="concurrencydirect3d-namespace"></a>Namespace Concurrency::direct3d

O namespace `direct3d` fornece funções que dão suporte à interoperabilidade do D3D. Ele permite que você use recursos do D3D para computação no código de AMP. Ele também permite o uso de recursos criados no código do AMP in D3D, sem a criação de cópias intermediárias redundantes. Você pode acelerar incrementalmente as seções de computação intensiva de seus aplicativos do DirectX usando C++ amp e usar a API do D3D em dados produzidos por meio de cálculos de amp.

## <a name="syntax"></a>Sintaxe

```cpp
namespace direct3d;
```

## <a name="members"></a>Membros

### <a name="classes"></a>Classes

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Classe scoped_d3d_access_lock](scoped-d3d-access-lock-class.md)|Um wrapper RAII para um bloqueio de acesso do D3D em um objeto `accelerator_view`.|

### <a name="structures"></a>Estruturas

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Estrutura adopt_d3d_access_lock_t](adopt-d3d-access-lock-t-structure.md)|Tipo de marca para indicar que o bloqueio de acesso do D3D deve ser adotado em vez de adquirido.|

### <a name="functions"></a>{1&gt;Funções&lt;1}

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[abs](concurrency-direct3d-namespace-functions-amp.md#abs)|Retorna o valor absoluto do argumento|
|[fixe](concurrency-direct3d-namespace-functions-amp.md#clamp)|Sobrecarregado. Coloca _X para o _Min e o intervalo de _Max especificados|
|[countbits](concurrency-direct3d-namespace-functions-amp.md#countbits)|Conta o número de conjuntos de bits em _X|
|[create_accelerator_view](concurrency-direct3d-namespace-functions-amp.md#create_accelerator_view)|Cria uma [classe accelerator_view](accelerator-view-class.md) de um ponteiro para uma interface de dispositivo Direct3D|
|[d3d_access_lock](concurrency-direct3d-namespace-functions-amp.md#d3d_access_lock)|Adquire um bloqueio em um accelerator_view para executar operações D3D com segurança em recursos compartilhados com o accelerator_view|
|[d3d_access_try_lock](concurrency-direct3d-namespace-functions-amp.md#d3d_access_try_lock)|Tentativa de adquirir o bloqueio de acesso do D3D em um accelerator_view sem bloqueio.|
|[d3d_access_unlock](concurrency-direct3d-namespace-functions-amp.md#d3d_access_unlock)|Libere o bloqueio de acesso do D3D no accelerator_view fornecido.|
|[firstbithigh](concurrency-direct3d-namespace-functions-amp.md#firstbithigh)|Obtém o local do primeiro bit definido em _X, a partir do bit de ordem mais alto e trabalhando para baixo|
|[firstbitlow](concurrency-direct3d-namespace-functions-amp.md#firstbitlow)|Obtém o local do primeiro bit definido em _X, começando do bit mais baixo e trabalhando para cima|
|[get_buffer](concurrency-direct3d-namespace-functions-amp.md#get_buffer)|Obter a interface do buffer do D3D subjacente a uma matriz.|
|[imax](concurrency-direct3d-namespace-functions-amp.md#imax)|Compara dois valores, retornando o valor que é maior.|
|[imin](concurrency-direct3d-namespace-functions-amp.md#imin)|Compara dois valores, retornando o valor menor.|
|[is_timeout_disabled](concurrency-direct3d-namespace-functions-amp.md#is_timeout_disabled)|Retorna um sinalizador booliano indicando se o tempo limite está desabilitado para o accelerator_view especificado.|
|[Mad](concurrency-direct3d-namespace-functions-amp.md#mad)|Sobrecarregado. Executa uma operação aritmética de multiplicar/adicionar em três argumentos: _X \* _Y + _Z|
|[make_array](concurrency-direct3d-namespace-functions-amp.md#make_array)|Crie uma matriz de um ponteiro de interface de buffer do D3D.|
|[ruído](concurrency-direct3d-namespace-functions-amp.md#noise)|Gera um valor aleatório usando o algoritmo de ruído do Perlm|
|[radianos](concurrency-direct3d-namespace-functions-amp.md#radians)|Converte _X de graus em radianos|
|[RCP](concurrency-direct3d-namespace-functions-amp.md#rcp)|Calcula um recíproco rápido e aproximado do argumento|
|[reversebits](concurrency-direct3d-namespace-functions-amp.md#reversebits)|Inverte a ordem dos bits em _X|
|[remover](concurrency-direct3d-namespace-functions-amp.md#saturate)|Coloca _X dentro do intervalo de 0 a 1|
|[sign](concurrency-direct3d-namespace-functions-amp.md#sign)|Sobrecarregado. Retorna o sinal do argumento|
|[smoothstep](concurrency-direct3d-namespace-functions-amp.md#smoothstep)|Retorna uma interpolação de Hermite suave entre 0 e 1, se _X estiver no intervalo [_Min, _Max].|
|[etapa](concurrency-direct3d-namespace-functions-amp.md#step)|Compara dois valores, retornando 0 ou 1 com base em qual valor é maior|
|[scanner](concurrency-direct3d-namespace-functions-amp.md#umax)|Compara dois valores não assinados, retornando o valor que é maior.|
|[umin](concurrency-direct3d-namespace-functions-amp.md#umin)|Compara dois valores não assinados, retornando o valor menor.|

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** amp. h

**Namespace:** Simultaneidade

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
