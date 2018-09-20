---
title: Funções do namespace Concurrency::Direct3D (AMP) | Microsoft Docs
ms.custom: ''
ms.date: 08/31/2018
ms.topic: reference
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
dev_langs:
- C++
ms.assetid: 28943b62-52c9-42dc-baf1-ca7b095c1a19
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4fc56ca800b3e6028d26a64be7323a681589430e
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46426049"
---
# <a name="concurrencydirect3d-namespace-functions-amp"></a>Funções do namespace Concurrency::Direct3D (AMP)

||||
|-|-|-|
|[abs](#abs)|[clamp](#clamp)|[countbits](#countbits)|
|[create_accelerator_view](#create_accelerator_view)|[d3d_access_lock](#d3d_access_lock)||
|[d3d_access_try_lock](#d3d_access_try_lock)|[d3d_access_unlock](#d3d_access_unlock)|[firstbithigh](#firstbithigh)|
|[firstbitlow](#firstbitlow)|[get_buffer](#get_buffer)|[get_device](#get_device)|
|[imax](#imax)|[imin](#imin)|[is_timeout_disabled](#is_timeout_disabled)|
|[mad](#mad)|[make_array](#make_array)|[noise](#noise)|
|[radianos](#radians)|[rcp](#rcp)|[reversebits](#reversebits)|
|[saturate](#saturate)|[sign](#sign)|[smoothstep](#smoothstep)|
|[step](#step)|[umax](#umax)|[umin](#umin)|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp. h **Namespace:** simultaneidade

##  <a name="abs"></a>  abs

Retorna o valor absoluto do argumento

```
inline int abs(int _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*X*<br/>
Valor inteiro

### <a name="return-value"></a>Valor de retorno

Retorna o valor absoluto do argumento.

##  <a name="clamp"></a>  clamp

Calcula o valor do primeiro argumento especificado restrito a um intervalo definido por segundo e terceiro argumentos especificados.

```
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

*X*<br/>
O valor a ser apertado

*Min*<br/>
O limite inferior do intervalo de compressão.

*Max*<br/>
O limite superior do intervalo de compressão.

### <a name="return-value"></a>Valor de retorno

O valor apertado de `_X`.

##  <a name="countbits"></a>  countbits

Conta o número de bits definidos em x

```
inline unsigned int countbits(unsigned int _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*X*<br/>
Valor inteiro sem sinal

### <a name="return-value"></a>Valor de retorno

Retorna o número de bits definidos em x

## <a name="create_accelerator_view"></a> create_accelerator_view

Cria uma [accelerator_view](accelerator-view-class.md) objeto de um ponteiro para uma interface de dispositivo de Direct3D.

## <a name="syntax"></a>Sintaxe

```
accelerator_view create_accelerator_view(
    IUnknown * _D3D_device
    queuing_mode _Qmode = queuing_mode_automatic);

accelerator_view create_accelerator_view(
    accelerator& _Accelerator,
    bool _Disable_timeout
    queuing_mode _Qmode = queuing_mode_automatic);
```

#### <a name="parameters"></a>Parâmetros

*_Accelerator*<br/>
O acelerador em que o novo accelerator_view deverá ser criado.

*_D3D_device*<br/>
O ponteiro para a interface do dispositivo Direct3D.

*_Disable_timeout*<br/>
Um parâmetro booliano que especifica se o tempo limite deve ser desabilitado para o accelerator_view recém-criado. Isso corresponde ao sinalizador D3D11_CREATE_DEVICE_DISABLE_GPU_TIMEOUT para a criação do dispositivo Direct3D e é usado para indicar se o sistema operacional deve permitir cargas de trabalho que levam mais de 2 segundos para executar sem redefinir o dispositivo pelo tempo limite do Windows mecanismo de detecção e recuperação. O uso desse sinalizador é recomendado se você precisar executar tarefas demoradas em accelerator_view.

*_Qmode*<br/>
O [queuing_mode](concurrency-namespace-enums-amp.md#queuing_mode) a ser usado para o accelerator_view recém-criado. Este parâmetro tem um valor padrão de `queuing_mode_automatic`.

## <a name="return-value"></a>Valor de retorno

O `accelerator_view` objeto criado da interface do dispositivo passada do Direct3D.

## <a name="remarks"></a>Comentários

Essa função cria um novo `accelerator_view` objeto de um ponteiro existente para uma interface de dispositivo de Direct3D. Se a chamada de função for bem-sucedida, a contagem de referência do parâmetro é incrementada por meio de um `AddRef` chamada para a interface. Com segurança, você pode liberar o objeto quando ele não é mais necessária em seu código de DirectX. Se a chamada de método falhar, uma [runtime_exception](runtime-exception-class.md) é gerada.

O `accelerator_view` objeto criado por você usando essa função é thread-safe. Você deve sincronizar simultaneamente o uso do `accelerator_view` objeto. Uso simultâneo de não sincronizado o `accelerator_view` objeto e a interface bruta do ID3D11Device causa um comportamento indefinido.

O tempo de execução C++ AMP fornece informações de erro detalhadas no modo de depuração usando a camada de depuração do D3D se você usar o `D3D11_CREATE_DEVICE_DEBUG` sinalizador.

##  <a name="d3d_access_lock"></a>  d3d_access_lock

Adquira um bloqueio em um accelerator_view com a finalidade de executar operações de D3D em recursos compartilhados com o accelerator_view de forma segura. O accelerator_view e todos os recursos de C++ AMP associados a esse accelerator_view internamente utilizam esse bloqueio ao executar operações e bloquearão enquanto outro thread mantém o bloqueio de acesso D3D. Esse bloqueio não é recursivo: é um comportamento indefinido para chamar essa função a partir de um thread que já mantém o bloqueio. Ele é um comportamento indefinido executar operações no accelerator_view ou em qualquer contêiner de dados associado ao accelerator_view do thread que mantém o bloqueio de acesso D3D. Consulte também scoped_d3d_access_lock, uma classe de estilo de RAII para um bloqueio de acesso D3D com base no escopo.

```
void __cdecl d3d_access_lock(accelerator_view& _Av);
```

### <a name="parameters"></a>Parâmetros

*_Av*<br/>
O accelerator_view para bloquear.

##  <a name="d3d_access_try_lock"></a>  d3d_access_try_lock

Tentativa de adquirir o bloqueio de acesso de D3D em um accelerator_view sem bloqueio.

```
bool __cdecl d3d_access_try_lock(accelerator_view& _Av);
```

### <a name="parameters"></a>Parâmetros

*_Av*<br/>
O accelerator_view para bloquear.

### <a name="return-value"></a>Valor de retorno

True se o bloqueio foi adquirido, ou false se ele é mantido atualmente por outro thread.

##  <a name="d3d_access_unlock"></a>  d3d_access_unlock

Libere o bloqueio de acesso de D3D no accelerator_view determinado. Se o thread de chamada não mantém o bloqueio no accelerator_view, os resultados são indefinidos.

```
void __cdecl d3d_access_unlock(accelerator_view& _Av);
```

### <a name="parameters"></a>Parâmetros

*_Av*<br/>
O accelerator_view para o qual o bloqueio for lançada.

##  <a name="firstbithigh"></a>  firstbithigh

Obtém o local do primeiro bit definido em x, começando pelo bit de ordem mais alta e a mudança para o bit de ordem mais baixa.

```
inline int firstbithigh(int _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*X*<br/>
Valor inteiro

### <a name="return-value"></a>Valor de retorno

O local do primeiro bit definido

##  <a name="firstbitlow"></a>  firstbitlow

Obtém o local do primeiro bit definido em x, começando pelo bit de ordem mais baixa e trabalhando para o bit de ordem mais alta.

```
inline int firstbitlow(int _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*X*<br/>
Valor inteiro

### <a name="return-value"></a>Valor de retorno

Retorna o local do primeiro bit definido

##  <a name="get_buffer"></a>  get_buffer

Obtenha a interface do buffer Direct3D subjacente à matriz especificada.

```
template<
    typename value_type,
    int _Rank
>
IUnknown *get_buffer(
    const array<value_type, _Rank>& _Array)  ;
```

### <a name="parameters"></a>Parâmetros

*value_type*<br/>
O tipo dos elementos na matriz.

*_Rank*<br/>
A classificação da matriz.

*Array*<br/>
Uma matriz em um accelerator_view Direct3D para o qual a interface do buffer Direct3D subjacente é retornada.

### <a name="return-value"></a>Valor de retorno

O ponteiro de interface IUnknown correspondente ao buffer Direct3D subjacente da matriz.

## <a name="a-namegetdevice-getdevice"></a><a name="get_device"> get_device

Obter a interface de dispositivo D3D subjacente a um accelerator_view.

```
IUnknown* get_device(const accelerator_view Av);
```

### <a name="parameters"></a>Parâmetros

*AV*<br/>
O accelerator_view de D3D para o qual a interface do dispositivo D3D subjacente é retornada.

### <a name="return-value"></a>Valor retornado

O `IUnknown` ponteiro de interface do dispositivo D3D subjacente accelerator_view.

##  <a name="imax"></a>  imax

Determinar o valor numérico máximo dos argumentos

```
inline int imax(
    int _X,
    int _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*X*<br/>
Valor inteiro

*Y*<br/>
Valor inteiro

### <a name="return-value"></a>Valor de retorno

Retorna o valor numérico máximo dos argumentos

##  <a name="imin"></a>  imin

Determinar o valor numérico mínimo dos argumentos

```
inline int imin(
    int _X,
    int _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*X*<br/>
Valor inteiro

*Y*<br/>
Valor inteiro

### <a name="return-value"></a>Valor de retorno

Retornar o valor numérico mínimo dos argumentos

##  <a name="is_timeout_disabled"></a>  is_timeout_disabled

Retorna um sinalizador booliano que indica se o tempo limite está desativado para o accelerator_view especificado. Isso corresponde ao sinalizador D3D11_CREATE_DEVICE_DISABLE_GPU_TIMEOUT para a criação do dispositivo Direct3D.

```
bool __cdecl is_timeout_disabled(const accelerator_view& _Accelerator_view);
```

### <a name="parameters"></a>Parâmetros

*_Accelerator_view*<br/>
O accelerator_view para o qual o tempo limite de desativar a configuração será consultado.

### <a name="return-value"></a>Valor de retorno

Um sinalizador booliano que indica se o tempo limite está desativado para o accelerator_view especificado.

##  <a name="mad"></a>  mad

Calcula o produto do primeiro e o segundo argumento especificado, em seguida, adiciona o terceiro argumento especificado.

```
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

*X*<br/>
O primeiro argumento especificado.

*Y*<br/>
O segundo argumento especificado.

*Z*<br/>
O terceiro argumento especificado.

### <a name="return-value"></a>Valor de retorno

O resultado de `_X` \* `_Y`  +  `_Z`.

##  <a name="make_array"></a>  make_array

Crie uma matriz de um ponteiro de interface do buffer Direct3D.

```
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

*value_type*<br/>
O tipo de elemento da matriz a ser criado.

*_Rank*<br/>
A classificação da matriz a ser criada.

*_Extent*<br/>
Uma extensão que descreve a forma do agregado da matriz.

*_Rv*<br/>
Uma exibição do acelerador D3D em que a matriz deve ser criado.

*_D3D_buffer*<br/>
Ponteiro de interface IUnknown do buffer D3D para criar a matriz.

### <a name="return-value"></a>Valor de retorno

Uma matriz criada usando o buffer Direct3D fornecido.

##  <a name="noise"></a>  ruído

Gera um valor aleatório usando o algoritmo de ruído de Perlin

```
inline float noise(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*X*<br/>
Valor de ponto flutuante do qual gerar ruído de Perlin

### <a name="return-value"></a>Valor de retorno

Retorna o valor de ruído de Perlin a dentro de um intervalo entre -1 e 1

##  <a name="radians"></a>  radianos

Converte x de graus em radianos

```
inline float radians(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna x convertido de graus em radianos

##  <a name="rcp"></a>  rcp

Calcula o recíproco do argumento especificado usando uma aproximação rápida.

```
inline float rcp(float _X) restrict(amp);

inline double rcp(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*X*<br/>
O valor para o qual calcular o recíproco.

### <a name="return-value"></a>Valor de retorno

O recíproco do argumento especificado.

##  <a name="reversebits"></a>  reversebits

Inverte a ordem dos bits em x

```
inline unsigned int reversebits(unsigned int _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*X*<br/>
Valor inteiro sem sinal

### <a name="return-value"></a>Valor de retorno

Retorna o valor com a ordem de bit invertida em x

##  <a name="saturate"></a>  saturar

Aperta o x dentro do intervalo de 0 a 1

```
inline float saturate(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna x fixado dentro do intervalo de 0 a 1

##  <a name="sign"></a>  logon

Determina o sinal do argumento especificado.

```
inline int sign(int _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*X*<br/>
Valor inteiro

### <a name="return-value"></a>Valor de retorno

O sinal do argumento.

##  <a name="smoothstep"></a>  smoothstep

Retorna uma interpolação suave de Hermite entre 0 e 1, se x está no intervalo [ min, Max].

```
inline float smoothstep(
    float _Min,
    float _Max,
    float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*Min*<br/>
Valor de ponto flutuante

*Max*<br/>
Valor de ponto flutuante

*X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna 0 se x for menor que min; 1 se x for maior que max; Caso contrário, um valor entre 0 e 1 se x está no intervalo [ min, Max]

##  <a name="step"></a>  Etapa

Compara dois valores, retornando 0 ou 1, com base em qual valor é maior

```
inline float step(
    float _Y,
    float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*Y*<br/>
Valor de ponto flutuante

*X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retornará 1 se o x for maior que ou igual a y; Caso contrário, 0

##  <a name="umax"></a>  umax

Determinar o valor numérico máximo dos argumentos

```
inline unsigned int umax(
    unsigned int _X,
    unsigned int _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*X*<br/>
Valor inteiro

*Y*<br/>
Valor inteiro

### <a name="return-value"></a>Valor de retorno

Retorna o valor numérico máximo dos argumentos

##  <a name="umin"></a>  umin

Determinar o valor numérico mínimo dos argumentos

```
inline unsigned int umin(
    unsigned int _X,
    unsigned int _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*X*<br/>
Valor inteiro

*Y*<br/>
Valor inteiro

### <a name="return-value"></a>Valor de retorno

Retornar o valor numérico mínimo dos argumentos

## <a name="see-also"></a>Consulte também

[Namespace Concurrency::direct3d](concurrency-direct3d-namespace.md)
