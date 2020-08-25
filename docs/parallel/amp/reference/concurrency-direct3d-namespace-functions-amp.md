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
ms.openlocfilehash: bf98249001c2b8227581fbbbcceeebd085e5d820
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88831106"
---
# <a name="concurrencydirect3d-namespace-functions-amp"></a>Funções de namespace Concurrency::direct3d (AMP)

:::row:::
   :::column span="":::
      [ABS](#abs)\
      [fixe](#clamp)\
      [countbits](#countbits)\
      [create_accelerator_view](#create_accelerator_view)\
      [d3d_access_lock](#d3d_access_lock)\
      [d3d_access_try_lock](#d3d_access_try_lock)\
      [d3d_access_unlock](#d3d_access_unlock)
   :::column-end:::
   :::column span="":::
      [firstbithigh](#firstbithigh)\
      [firstbitlow](#firstbitlow)\
      [get_buffer](#get_buffer)\
      [get_device](#get_device)\
      [imax](#imax)\
      [imin](#imin)\
      [is_timeout_disabled](#is_timeout_disabled)
   :::column-end:::
   :::column span="":::
      [Mad](#mad)\
      [make_array](#make_array)\
      [ruído](#noise)\
      [radianos](#radians)\
      [RCP](#rcp)\
      [reversebits](#reversebits)
   :::column-end:::
   :::column span="":::
      [remover](#saturate)\
      [Assine](#sign)\
      [smoothstep](#smoothstep)\
      [etapa](#step)\
      [scanner](#umax)\
      [umin](#umin)
   :::column-end:::
:::row-end:::

## <a name="requirements"></a>Requisitos

**Cabeçalho:** namespace amp. h **:** simultaneidade

## <a name="abs"></a><a name="abs"></a> ABS

Retorna o valor absoluto do argumento

```cpp
inline int abs(int _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor inteiro

### <a name="return-value"></a>Valor Retornado

Retorna o valor absoluto do argumento.

## <a name="clamp"></a><a name="clamp"></a> fixe

Computa o valor do primeiro argumento especificado clamped para um intervalo definido pelo segundo e terceiro argumentos especificados.

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

### <a name="parameters"></a>parâmetros

*_X*<br/>
O valor a ser clampeddo

*_Min*<br/>
O limite inferior do intervalo de fixação MSS.

*_Max*<br/>
O limite superior do intervalo de fixação MSS.

### <a name="return-value"></a>Valor Retornado

O valor de clamped de `_X` .

## <a name="countbits"></a><a name="countbits"></a> countbits

Conta o número de conjuntos de bits em _X

```cpp
inline unsigned int countbits(unsigned int _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor inteiro sem sinal

### <a name="return-value"></a>Valor Retornado

Retorna o número de conjuntos de bits em _X

## <a name="create_accelerator_view"></a><a name="create_accelerator_view"></a> create_accelerator_view

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

### <a name="parameters"></a>parâmetros

*_Accelerator*<br/>
O acelerador no qual o novo accelerator_view será criado.

*_D3D_device*<br/>
O ponteiro para a interface do dispositivo Direct3D.

*_Disable_timeout*<br/>
Um parâmetro booliano que especifica se o tempo limite deve ser desabilitado para a accelerator_view recém-criada. Isso corresponde ao sinalizador D3D11_CREATE_DEVICE_DISABLE_GPU_TIMEOUT para a criação do dispositivo Direct3D e é usado para indicar se o sistema operacional deve permitir cargas de trabalho que levam mais de 2 segundos para serem executadas sem redefinir o dispositivo de acordo com a detecção de tempo limite do Windows e o mecanismo de recuperação. O uso desse sinalizador é recomendado se você precisar executar tarefas demoradas no accelerator_view.

*_Qmode*<br/>
O [queuing_mode](concurrency-namespace-enums-amp.md#queuing_mode) a ser usado para a accelerator_view recém-criada. Esse parâmetro tem um valor padrão de `queuing_mode_automatic` .

## <a name="return-value"></a>Valor Retornado

O `accelerator_view` objeto criado a partir da interface de dispositivo Direct3D passada.

## <a name="remarks"></a>Comentários

Essa função cria um novo `accelerator_view` objeto a partir de um ponteiro existente para uma interface de dispositivo Direct3D. Se a chamada de função for realizada com sucesso, a contagem de referência do parâmetro será incrementada por meio de uma `AddRef` chamada para a interface. Você pode liberar o objeto com segurança quando ele não for mais necessário em seu código DirectX. Se a chamada do método falhar, um [runtime_exception](runtime-exception-class.md) será lançado.

O `accelerator_view` objeto que você cria usando essa função é thread-safe. Você deve sincronizar o uso simultâneo do `accelerator_view` objeto. O uso simultâneo não sincronizado do `accelerator_view` objeto e a interface ID3D11Device bruta causam um comportamento indefinido.

O tempo de execução do C++ AMP fornece informações detalhadas de erro no modo de depuração usando a camada de depuração do D3D se você usar o `D3D11_CREATE_DEVICE_DEBUG` sinalizador.

## <a name="d3d_access_lock"></a><a name="d3d_access_lock"></a> d3d_access_lock

Adquira um bloqueio em um accelerator_view para a finalidade de executar operações D3D com segurança em recursos compartilhados com o accelerator_view. O accelerator_view e todos os recursos de C++ AMP associados a esse accelerator_view usam internamente esse bloqueio ao executar operações e serão bloqueados enquanto outro thread mantém o bloqueio de acesso do D3D. Este bloqueio não é Recursivo: é um comportamento indefinido para chamar essa função de um thread que já contém o bloqueio. É um comportamento indefinido para executar operações no accelerator_view ou em qualquer contêiner de dados associado ao accelerator_view do thread que mantém o bloqueio de acesso do D3D. Consulte também scoped_d3d_access_lock, uma classe de estilo RAII para um bloqueio de acesso do D3D com base no escopo.

```cpp
void __cdecl d3d_access_lock(accelerator_view& _Av);
```

### <a name="parameters"></a>parâmetros

*_Av*<br/>
O accelerator_view a ser bloqueado.

## <a name="d3d_access_try_lock"></a><a name="d3d_access_try_lock"></a> d3d_access_try_lock

Tentativa de adquirir o bloqueio de acesso do D3D em um accelerator_view sem bloqueio.

```cpp
bool __cdecl d3d_access_try_lock(accelerator_view& _Av);
```

### <a name="parameters"></a>parâmetros

*_Av*<br/>
O accelerator_view a ser bloqueado.

### <a name="return-value"></a>Valor Retornado

true se o bloqueio tiver sido adquirido ou false se ele estiver sendo mantido por outro thread.

## <a name="d3d_access_unlock"></a><a name="d3d_access_unlock"></a> d3d_access_unlock

Libere o bloqueio de acesso do D3D no accelerator_view fornecido. Se o thread de chamada não mantiver o bloqueio no accelerator_view os resultados serão indefinidos.

```cpp
void __cdecl d3d_access_unlock(accelerator_view& _Av);
```

### <a name="parameters"></a>parâmetros

*_Av*<br/>
O accelerator_view para o qual o bloqueio deve ser liberado.

## <a name="firstbithigh"></a><a name="firstbithigh"></a> firstbithigh

Obtém o local do primeiro bit definido em _X, começando com o bit de ordem mais alta e movendo para o bit de ordem mais baixa.

```cpp
inline int firstbithigh(int _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor inteiro

### <a name="return-value"></a>Valor Retornado

O local do primeiro bit definido

## <a name="firstbitlow"></a><a name="firstbitlow"></a> firstbitlow

Obtém o local do primeiro bit definido em _X, começando com o bit de ordem mais baixa e trabalhando para o bit de ordem mais alta.

```cpp
inline int firstbitlow(int _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor inteiro

### <a name="return-value"></a>Valor Retornado

Retorna o local do primeiro bit definido

## <a name="get_buffer"></a><a name="get_buffer"></a> get_buffer

Obter a interface do buffer do Direct3D subjacente à matriz especificada.

```cpp
template<
    typename value_type,
    int _Rank
>
IUnknown *get_buffer(
    const array<value_type, _Rank>& _Array)  ;
```

### <a name="parameters"></a>parâmetros

*value_type*<br/>
O tipo dos elementos na matriz.

*_Rank*<br/>
A classificação da matriz.

*_Array*<br/>
Uma matriz em um accelerator_view Direct3D para o qual a interface subjacente do buffer do Direct3D é retornada.

### <a name="return-value"></a>Valor Retornado

O ponteiro de interface IUnknown que corresponde ao buffer do Direct3D subjacente à matriz.

## <a name="a-nameget_device-get_device"></a><a name="get_device"> get_device

Obtenha a interface do dispositivo D3D subjacente a uma accelerator_view.

```cpp
IUnknown* get_device(const accelerator_view Av);
```

### <a name="parameters"></a>parâmetros

*AV*<br/>
O accelerator_view D3D para o qual a interface de dispositivo D3D subjacente é retornada.

### <a name="return-value"></a>Retornar valor

O `IUnknown` ponteiro de interface do dispositivo D3D subjacente ao accelerator_view.

## <a name="imax"></a><a name="imax"></a> imax

Determinar o valor numérico máximo dos argumentos

```cpp
inline int imax(
    int _X,
    int _Y) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor inteiro

*_Y*<br/>
Valor inteiro

### <a name="return-value"></a>Valor Retornado

Retornar o valor numérico máximo dos argumentos

## <a name="imin"></a><a name="imin"></a> imin

Determinar o valor numérico mínimo dos argumentos

```cpp
inline int imin(
    int _X,
    int _Y) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor inteiro

*_Y*<br/>
Valor inteiro

### <a name="return-value"></a>Valor Retornado

Retornar o valor numérico mínimo dos argumentos

## <a name="is_timeout_disabled"></a><a name="is_timeout_disabled"></a> is_timeout_disabled

Retorna um sinalizador booliano indicando se o tempo limite está desabilitado para o accelerator_view especificado. Isso corresponde ao sinalizador de D3D11_CREATE_DEVICE_DISABLE_GPU_TIMEOUT para a criação do dispositivo Direct3D.

```cpp
bool __cdecl is_timeout_disabled(const accelerator_view& _Accelerator_view);
```

### <a name="parameters"></a>parâmetros

*_Accelerator_view*<br/>
O accelerator_view para o qual a configuração de tempo limite desabilitado deve ser consultada.

### <a name="return-value"></a>Valor Retornado

Um sinalizador booliano que indica se o tempo limite está desabilitado para o accelerator_view especificado.

## <a name="mad"></a><a name="mad"></a> Mad

Computa o produto do primeiro e o segundo argumento especificado e, em seguida, adiciona o terceiro argumento especificado.

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

### <a name="parameters"></a>parâmetros

*_X*<br/>
O primeiro argumento especificado.

*_Y*<br/>
O segundo argumento especificado.

*_Z*<br/>
O terceiro argumento especificado.

### <a name="return-value"></a>Valor Retornado

O resultado de `_X` \* `_Y`  +  `_Z` .

## <a name="make_array"></a><a name="make_array"></a> make_array

Crie uma matriz de um ponteiro de interface de buffer do Direct3D.

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

### <a name="parameters"></a>parâmetros

*value_type*<br/>
O tipo de elemento da matriz a ser criada.

*_Rank*<br/>
A classificação da matriz a ser criada.

*_Extent*<br/>
Uma extensão que descreve a forma da agregação de matriz.

*_Rv*<br/>
Uma exibição do acelerador D3D na qual a matriz deve ser criada.

*_D3D_buffer*<br/>
Ponteiro de interface IUnknown do buffer do D3D do qual criar a matriz.

### <a name="return-value"></a>Valor Retornado

Uma matriz criada usando o buffer do Direct3D fornecido.

## <a name="noise"></a><a name="noise"></a> ruído

Gera um valor aleatório usando o algoritmo de ruído do Perlm

```cpp
inline float noise(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante do qual gerar ruído de Perl

### <a name="return-value"></a>Valor Retornado

Retorna o valor de ruído de Perlm dentro de um intervalo entre-1 e 1

## <a name="radians"></a><a name="radians"></a> radianos

Converte _X de graus em radianos

```cpp
inline float radians(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna _X convertido de graus em radianos

## <a name="rcp"></a><a name="rcp"></a> RCP

Computa o recíproco do argumento especificado usando uma aproximação rápida.

```cpp
inline float rcp(float _X) restrict(amp);

inline double rcp(double _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
O valor para o qual computar o recíproco.

### <a name="return-value"></a>Valor Retornado

O recíproco do argumento especificado.

## <a name="reversebits"></a><a name="reversebits"></a> reversebits

Inverte a ordem dos bits em _X

```cpp
inline unsigned int reversebits(unsigned int _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor inteiro sem sinal

### <a name="return-value"></a>Valor Retornado

Retorna o valor com a ordem de bits invertida em _X

## <a name="saturate"></a><a name="saturate"></a> remover

Coloca _X dentro do intervalo de 0 a 1

```cpp
inline float saturate(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna _X clamped dentro do intervalo de 0 a 1

## <a name="sign"></a><a name="sign"></a> Assine

Determina o sinal do argumento especificado.

```cpp
inline int sign(int _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor inteiro

### <a name="return-value"></a>Valor Retornado

O sinal do argumento.

## <a name="smoothstep"></a><a name="smoothstep"></a> smoothstep

Retorna uma interpolação de Hermite suave entre 0 e 1, se _X estiver no intervalo [_Min, _Max].

```cpp
inline float smoothstep(
    float _Min,
    float _Max,
    float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_Min*<br/>
Valor de ponto flutuante

*_Max*<br/>
Valor de ponto flutuante

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retornará 0 se _X for menor que _Min; 1 se _X for maior que _Max; caso contrário, um valor entre 0 e 1 se _X está no intervalo [_Min, _Max]

## <a name="step"></a><a name="step"></a> etapa

Compara dois valores, retornando 0 ou 1 com base em qual valor é maior

```cpp
inline float step(
    float _Y,
    float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_Y*<br/>
Valor de ponto flutuante

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retornará 1 se o _X for maior ou igual a _Y; caso contrário, 0

## <a name="umax"></a><a name="umax"></a> scanner

Determinar o valor numérico máximo dos argumentos

```cpp
inline unsigned int umax(
    unsigned int _X,
    unsigned int _Y) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor inteiro

*_Y*<br/>
Valor inteiro

### <a name="return-value"></a>Valor Retornado

Retornar o valor numérico máximo dos argumentos

## <a name="umin"></a><a name="umin"></a> umin

Determinar o valor numérico mínimo dos argumentos

```cpp
inline unsigned int umin(
    unsigned int _X,
    unsigned int _Y) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor inteiro

*_Y*<br/>
Valor inteiro

### <a name="return-value"></a>Valor Retornado

Retornar o valor numérico mínimo dos argumentos

## <a name="see-also"></a>Confira também

[Namespace Concurrency::direct3d](concurrency-direct3d-namespace.md)
