---
title: Funções de namespace Concurrency::direct3d (AMP)
ms.date: 08/31/2018
f1_keywords:
- amp/Concurrency::direct3d::abs
- amp/Concurrency::direct3d::countbits
- amp/Concurrency::direct3d::create_accelerator_view
- amp/Concurrency::direct3d::d3d_access_lock
- amp/Concurrency::direct3d::d3d_access_unlock
- amp/Concurrency::direct3d::firstbithigh
- amp/Concurrency::direct3d::get_buffer
- amp/Concurrency::direct3d::get_device
- amp/Concurrency::direct3d::imax
- amp/Concurrency::direct3d::is_timeout_disabled
- amp/Concurrency::direct3d::mad
- amp/Concurrency::direct3d::noise
- amp/Concurrency::direct3d::radians
- amp/Concurrency::direct3d::reversebits
- amp/Concurrency::direct3d::saturate
- amp/Concurrency::direct3d::smoothstep
- amp/Concurrency::direct3d::step
- amp/Concurrency::direct3d::umin
ms.assetid: 28943b62-52c9-42dc-baf1-ca7b095c1a19
ms.openlocfilehash: e21b1f2869ab81973b341abc5371714fbf8580e2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375930"
---
# <a name="concurrencydirect3d-namespace-functions-amp"></a>Funções de namespace Concurrency::direct3d (AMP)

||||
|-|-|-|
|[Abs](#abs)|[Braçadeira](#clamp)|[contagembits](#countbits)|
|[create_accelerator_view](#create_accelerator_view)|[d3d_access_lock](#d3d_access_lock)||
|[d3d_access_try_lock](#d3d_access_try_lock)|[d3d_access_unlock](#d3d_access_unlock)|[firstbithigh](#firstbithigh)|
|[firstbitlow](#firstbitlow)|[get_buffer](#get_buffer)|[get_device](#get_device)|
|[imax](#imax)|[imin](#imin)|[is_timeout_disabled](#is_timeout_disabled)|
|[Louco](#mad)|[make_array](#make_array)|[Ruído](#noise)|
|[Radianos](#radians)|[rcp](#rcp)|[reversos](#reversebits)|
|[Saturar](#saturate)|[Sinal](#sign)|[passo liso](#smoothstep)|
|[Passo](#step)|[Umax](#umax)|[umin](#umin)|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp.h **Namespace:** Concurrency

## <a name="abs"></a><a name="abs"></a>Abs

Devolve o valor absoluto do argumento

```cpp
inline int abs(int _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor inteiro

### <a name="return-value"></a>Valor retornado

Devolve o valor absoluto do argumento.

## <a name="clamp"></a><a name="clamp"></a>Braçadeira

Calcula o valor do primeiro argumento especificado fixado a um intervalo definido pelo segundo e terceiro argumentos especificados.

```cpp
inline float clamp(
    float _X,
    float _Min,
    float _Max) restrict(amp);

inline int clamp(
    int _X,
    int _Min,
    int _Max) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
O valor a ser fixado

*_Min*<br/>
O limite inferior da faixa de fixação.

*_Max*<br/>
O limite superior da faixa de fixação.

### <a name="return-value"></a>Valor retornado

O valor fixado de `_X`.

## <a name="countbits"></a><a name="countbits"></a>contagembits

Conta o número de bits definidos em _X

```cpp
inline unsigned int countbits(unsigned int _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor inteiro não assinado

### <a name="return-value"></a>Valor retornado

Retorna o número de bits definidos em _X

## <a name="create_accelerator_view"></a><a name="create_accelerator_view"></a>create_accelerator_view

Cria um objeto [accelerator_view](accelerator-view-class.md) de um ponteiro para uma interface de dispositivo Direct3D.

## <a name="syntax"></a>Sintaxe

```cpp
accelerator_view create_accelerator_view(
    IUnknown * _D3D_device
    queuing_mode _Qmode = queuing_mode_automatic);

accelerator_view create_accelerator_view(
    accelerator& _Accelerator,
    bool _Disable_timeout
    queuing_mode _Qmode = queuing_mode_automatic);
```

### <a name="parameters"></a>Parâmetros

*_Accelerator*<br/>
O acelerador no qual o novo accelerator_view deve ser criado.

*_D3D_device*<br/>
O ponteiro para a interface do dispositivo Direct3D.

*_Disable_timeout*<br/>
Um parâmetro booleano que especifica se o tempo livre deve ser desativado para o accelerator_view recém-criado. Isso corresponde à bandeira D3D11_CREATE_DEVICE_DISABLE_GPU_TIMEOUT para a criação do dispositivo Direct3D e é usado para indicar se o sistema operacional deve permitir cargas de trabalho que levam mais de 2 segundos para serem executadas sem redefinir o dispositivo pelo mecanismo de detecção e recuperação do tempo limite do Windows. O uso deste sinalizador é recomendado se você precisar executar tarefas demoradas no accelerator_view.

*_Qmode*<br/>
O [queuing_mode](concurrency-namespace-enums-amp.md#queuing_mode) para ser usado para o accelerator_view recém-criado. Este parâmetro tem um `queuing_mode_automatic`valor padrão de .

## <a name="return-value"></a>Valor retornado

O `accelerator_view` objeto criado a partir da interface do dispositivo Direct3D passada.

## <a name="remarks"></a>Comentários

Essa função cria `accelerator_view` um novo objeto de um ponteiro existente para uma interface de dispositivo Direct3D. Se a chamada de função for bem sucedida, a contagem `AddRef` de referência do parâmetro será incrementada por meio de uma chamada para a interface. Você pode liberar o objeto com segurança quando ele não for mais necessário em seu código DirectX. Se a chamada do método falhar, um [runtime_exception](runtime-exception-class.md) será lançado.

O `accelerator_view` objeto que você cria usando esta função é seguro para rosca. Você deve sincronizar o `accelerator_view` uso simultâneo do objeto. O uso simultâneo não sincronizado do `accelerator_view` objeto e da interface id3D11Sraw causa comportamento indefinido.

O tempo de execução C++ AMP fornece informações detalhadas de erro no `D3D11_CREATE_DEVICE_DEBUG` modo de depuração usando a camada Depuração D3D se você usar o sinalizador.

## <a name="d3d_access_lock"></a><a name="d3d_access_lock"></a>d3d_access_lock

Adquira um bloqueio em um accelerator_view com o propósito de realizar com segurança operações D3D em recursos compartilhados com a accelerator_view. O accelerator_view e todos os recursos C++ AMP associados a este accelerator_view tomam internamente esse bloqueio ao executar operações e bloquearão enquanto outro segmento mantém o bloqueio de acesso D3D. Este bloqueio não é recursivo: É um comportamento indefinido chamar essa função de um segmento que já segura o bloqueio. É um comportamento indefinido realizar operações no accelerator_view ou em qualquer contêiner de dados associado ao accelerator_view a partir do segmento que mantém o bloqueio de acesso D3D. Veja também scoped_d3d_access_lock, uma classe no estilo RAII para um bloqueio de acesso D3D baseado em escopo.

```cpp
void __cdecl d3d_access_lock(accelerator_view& _Av);
```

### <a name="parameters"></a>Parâmetros

*_Av*<br/>
A accelerator_view para travar.

## <a name="d3d_access_try_lock"></a><a name="d3d_access_try_lock"></a>d3d_access_try_lock

Tente adquirir o bloqueio de acesso D3D em um accelerator_view sem bloqueio.

```cpp
bool __cdecl d3d_access_try_lock(accelerator_view& _Av);
```

### <a name="parameters"></a>Parâmetros

*_Av*<br/>
A accelerator_view para travar.

### <a name="return-value"></a>Valor retornado

verdade se o bloqueio foi adquirido, ou falso se ele é atualmente mantido por outro segmento.

## <a name="d3d_access_unlock"></a><a name="d3d_access_unlock"></a>d3d_access_unlock

Solte a trava de acesso D3D no accelerator_view dado. Se a linha de chamada não segurar a trava na accelerator_view os resultados estiverem indefinidos.

```cpp
void __cdecl d3d_access_unlock(accelerator_view& _Av);
```

### <a name="parameters"></a>Parâmetros

*_Av*<br/>
A accelerator_view para a qual a fechadura deve ser liberada.

## <a name="firstbithigh"></a><a name="firstbithigh"></a>firstbithigh

Obtém a localização do primeiro conjunto em _X, começando com a broca de maior ordem e movendo-se para a broca de menor ordem.

```cpp
inline int firstbithigh(int _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor inteiro

### <a name="return-value"></a>Valor retornado

A localização do bit do primeiro conjunto

## <a name="firstbitlow"></a><a name="firstbitlow"></a>firstbitlow

Obtém a localização do primeiro conjunto em _X, começando com a broca de menor ordem e trabalhando em direção à parte de ordem mais alta.

```cpp
inline int firstbitlow(int _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor inteiro

### <a name="return-value"></a>Valor retornado

Retorna A localização do primeiro bit definido

## <a name="get_buffer"></a><a name="get_buffer"></a>get_buffer

Obtenha a interface de buffer Direct3D subjacente à matriz especificada.

```cpp
template<
    typename value_type,
    int _Rank
>
IUnknown *get_buffer(
    const array<value_type, _Rank>& _Array)  ;
```

### <a name="parameters"></a>Parâmetros

*Value_type*<br/>
O tipo dos elementos na matriz.

*_Rank*<br/>
A classificação da matriz.

*_Array*<br/>
Uma matriz em um direct3D accelerator_view para a qual a interface de buffer Direct3D subjacente é devolvida.

### <a name="return-value"></a>Valor retornado

O ponteiro de interface IUnknown correspondente ao buffer Direct3D subjacente à matriz.

## <a name="a-nameget_device-get_device"></a><a name="get_device">get_device

Obtenha a interface do dispositivo D3D subjacente a um accelerator_view.

```cpp
IUnknown* get_device(const accelerator_view Av);
```

### <a name="parameters"></a>Parâmetros

*Av*<br/>
O D3D accelerator_view para o qual a interface do dispositivo D3D subjacente é devolvida.

### <a name="return-value"></a>Valor retornado

O `IUnknown` ponteiro de interface do dispositivo D3D subjacente ao accelerator_view.

## <a name="imax"></a><a name="imax"></a>Imax

Determine o valor nuémero máximo dos argumentos

```cpp
inline int imax(
    int _X,
    int _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor inteiro

*_Y*<br/>
Valor inteiro

### <a name="return-value"></a>Valor retornado

Devolva o valor numérico máximo dos argumentos

## <a name="imin"></a><a name="imin"></a>imin

Determine o valor numérico mínimo dos argumentos

```cpp
inline int imin(
    int _X,
    int _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor inteiro

*_Y*<br/>
Valor inteiro

### <a name="return-value"></a>Valor retornado

Devolva o valor numérico mínimo dos argumentos

## <a name="is_timeout_disabled"></a><a name="is_timeout_disabled"></a>is_timeout_disabled

Retorna uma bandeira booleana indicando se o tempo está desativado para o accelerator_view especificado. Isso corresponde à bandeira D3D11_CREATE_DEVICE_DISABLE_GPU_TIMEOUT para criação de dispositivos Direct3D.

```cpp
bool __cdecl is_timeout_disabled(const accelerator_view& _Accelerator_view);
```

### <a name="parameters"></a>Parâmetros

*_Accelerator_view*<br/>
A accelerator_view para a qual a configuração de tempo desativada deve ser consultada.

### <a name="return-value"></a>Valor retornado

Uma bandeira booleana indicando se o tempo está desativado para o accelerator_view especificado.

## <a name="mad"></a><a name="mad"></a>Louco

Calcula o produto do primeiro e segundo argumento especificado e, em seguida, adiciona o terceiro argumento especificado.

```cpp
inline float mad(
    float _X,
    float _Y,
    float _Z) restrict(amp);

inline double mad(
    double _X,
    double _Y,
    double _Z) restrict(amp);

inline int mad(
    int _X,
    int _Y,
    int _Z) restrict(amp);

inline unsigned int mad(
    unsigned int _X,
    unsigned int _Y,
    unsigned int _Z) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
O primeiro argumento especificado.

*_Y*<br/>
O segundo argumento especificado.

*_Z*<br/>
O terceiro argumento especificado.

### <a name="return-value"></a>Valor retornado

O resultado `_X` \* `_Y`  +  `_Z`de .

## <a name="make_array"></a><a name="make_array"></a>make_array

Crie uma matriz a partir de um ponteiro de interface de buffer Direct3D.

```cpp
template<
    typename value_type,
    int _Rank
>
array<value_type, _Rank> make_array(
    const extent<_Rank>& _Extent,
    const Concurrency::accelerator_view& _Rv,
    IUnknown* _D3D_buffer)  ;
```

### <a name="parameters"></a>Parâmetros

*Value_type*<br/>
O tipo de elemento da matriz a ser criada.

*_Rank*<br/>
A classificação da matriz a ser criada.

*_Extent*<br/>
Uma extensão que descreve a forma do agregado da matriz.

*_Rv*<br/>
Uma visão do acelerador D3D na qual a matriz deve ser criada.

*_D3D_buffer*<br/>
Ponteiro de interface IUnknown do buffer D3D para criar a matriz a partir de.

### <a name="return-value"></a>Valor retornado

Uma matriz criada usando o buffer Direct3D fornecido.

## <a name="noise"></a><a name="noise"></a>Ruído

Gera um valor aleatório usando o algoritmo de ruído Perlin

```cpp
inline float noise(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante a partir do qual gerar ruído Perlin

### <a name="return-value"></a>Valor retornado

Retorna o valor de ruído perlin dentro de uma faixa entre -1 e 1

## <a name="radians"></a><a name="radians"></a>Radianos

Converte _X de graus em radianos

```cpp
inline float radians(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retornos _X convertidos de graus para radianos

## <a name="rcp"></a><a name="rcp"></a>rcp

Calcula a recíproca do argumento especificado usando uma aproximação rápida.

```cpp
inline float rcp(float _X) restrict(amp);

inline double rcp(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
O valor para calcular o recíproco.

### <a name="return-value"></a>Valor retornado

A recíproca do argumento especificado.

## <a name="reversebits"></a><a name="reversebits"></a>reversos

Inverte a ordem dos bits em _X

```cpp
inline unsigned int reversebits(unsigned int _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor inteiro não assinado

### <a name="return-value"></a>Valor retornado

Retorna o valor com a ordem de bitinvertida em _X

## <a name="saturate"></a><a name="saturate"></a>Saturar

Grampos _X dentro da faixa de 0 a 1

```cpp
inline float saturate(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Devoluções _X fixadas dentro da faixa de 0 a 1

## <a name="sign"></a><a name="sign"></a>Sinal

Determina o sinal do argumento especificado.

```cpp
inline int sign(int _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor inteiro

### <a name="return-value"></a>Valor retornado

O sinal do argumento.

## <a name="smoothstep"></a><a name="smoothstep"></a>passo liso

Retorna uma interpolação hermita suave entre 0 e 1, se _X estiver na faixa [_Min, _Max].

```cpp
inline float smoothstep(
    float _Min,
    float _Max,
    float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Min*<br/>
Valor de ponto flutuante

*_Max*<br/>
Valor de ponto flutuante

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna 0 se _X for menor que _Min; 1 se _X for maior que _Max; caso contrário, um valor entre 0 e 1 se _X estiver na faixa [_Min, _Max]

## <a name="step"></a><a name="step"></a>Passo

Compara dois valores, retornando 0 ou 1 com base em qual valor é maior

```cpp
inline float step(
    float _Y,
    float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Y*<br/>
Valor de ponto flutuante

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna 1 se o _X for maior ou igual a _Y; caso contrário, 0

## <a name="umax"></a><a name="umax"></a>Umax

Determine o valor nuémero máximo dos argumentos

```cpp
inline unsigned int umax(
    unsigned int _X,
    unsigned int _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor inteiro

*_Y*<br/>
Valor inteiro

### <a name="return-value"></a>Valor retornado

Devolva o valor numérico máximo dos argumentos

## <a name="umin"></a><a name="umin"></a>umin

Determine o valor numérico mínimo dos argumentos

```cpp
inline unsigned int umin(
    unsigned int _X,
    unsigned int _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor inteiro

*_Y*<br/>
Valor inteiro

### <a name="return-value"></a>Valor retornado

Devolva o valor numérico mínimo dos argumentos

## <a name="see-also"></a>Confira também

[Namespace Concurrency::direct3d](concurrency-direct3d-namespace.md)
