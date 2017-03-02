---
title: "Funções de namespace Concurrency:: Direct3D (AMP) | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 28943b62-52c9-42dc-baf1-ca7b095c1a19
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 46cafc3c6d6f21eaf147ef0edfeca7f2c81d64e6
ms.lasthandoff: 02/25/2017

---
# <a name="concurrencydirect3d-namespace-functions-amp"></a>Funções de namespace Concurrency:: Direct3D (AMP)
||||  
|-|-|-|  
|[Função ABS](#abs)|[Função Clamp](#clamp)|[Função countbits](#countbits)|
|[Função create_accelerator_view](#create_accelerator_view)|||
|[Função d3d_access_lock](#d3d_access_lock)|[Função d3d_access_try_lock](#d3d_access_try_lock)|[Função d3d_access_unlock](#d3d_access_unlock)|  
|[Função firstbithigh](#firstbithigh)|[Função firstbitlow](#firstbitlow)|[Função get_buffer](#get_buffer)|  
|[Função IMAX](#imax)|[Função imin](#imin)|[Função is_timeout_disabled](#is_timeout_disabled)|  
|[Função MAD](#mad)|[Função make_array](#make_array)|[Função Noise](#noise)|  
|[Função radians](#radians)|[Função rcp](#rcp)|[Função reversebits](#reversebits)|  
|[Função saturate](#saturate)|[Função Sign](#sign)|[Função smoothstep](#smoothstep)|  
|[Função Step](#step)|[Função UMAX](#umax)|[Função umin](#umin)|  
  
##  <a name="a-nameabsa--abs-function"></a><a name="abs"></a>Função ABS  
 Retorna o valor absoluto do argumento  
  
```  
inline int abs(int _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor inteiro  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor absoluto do argumento.  
  
##  <a name="a-nameclampa--clamp-function"></a><a name="clamp"></a>Função Clamp  
 Calcula o valor do primeiro argumento especificado fixado como um intervalo definido por segundo e terceiro argumentos especificados.  
  
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
 `_X`  
 O valor a ser fixado  
  
 `_Min`  
 O limite inferior do intervalo clamping.  
  
 `_Max`  
 O limite superior do intervalo de clamping.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor fixado de `_X`.  
  
##  <a name="a-namecountbitsa--countbits-function"></a><a name="countbits"></a>Função countbits  
 Conta o número de bits de conjunto em x  
  
```  
inline unsigned int countbits(unsigned int _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor inteiro não assinado  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de bits de conjunto em x  

## <a name="a-namecreateacceleratorviewa-createacceleratorview-function"></a><a name="create_accelerator_view"></a>Função create_accelerator_view
Cria um [accelerator_view](accelerator-view-class.md) objeto de um ponteiro para uma interface de dispositivo Direct3D.  
  
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
 `_Accelerator`  
 O acelerador no qual o novo accelerator_view será criado.  
  
 `_D3D_device`  
 O ponteiro para a interface do dispositivo Direct3D.  
  
 `_Disable_timeout`  
 Um parâmetro booleano que especifica se o tempo limite deve ser desabilitado para o accelerator_view recém-criado. Isso corresponde ao sinalizador D3D11_CREATE_DEVICE_DISABLE_GPU_TIMEOUT para criação de dispositivo Direct3D e é usado para indicar se o sistema operacional deve permitir cargas de trabalho que levam mais de 2 segundos para ser executada sem redefinir o dispositivo de acordo com a detecção de tempo limite do Windows e o mecanismo de recuperação. O uso desse sinalizador é recomendado se você precisar executar tarefas demoradas o accelerator_view.  
  
 `_Qmode`  
 O [queuing_mode](concurrency-namespace-enums-amp.md#queuing_mode) a ser usado para o accelerator_view recém-criado. Esse parâmetro tem um valor padrão de `queuing_mode_automatic`.  
  
## <a name="return-value"></a>Valor de retorno  
 O `accelerator_view` objeto criado da interface do dispositivo Direct3D passado.  
  
## <a name="remarks"></a>Comentários  
 Esta função cria um novo `accelerator_view` objeto de um ponteiro existente para uma interface de dispositivo Direct3D. Se a chamada de função for bem-sucedida, a contagem de referência do parâmetro é incrementada por meio de um `AddRef` chamada para a interface. Com segurança, você pode liberar o objeto quando ele não é mais necessário em seu código do DirectX. Se a chamada de método falhar, uma [runtime_exception](runtime-exception-class.md) é lançada.  
  
 O `accelerator_view` objeto que você criar usando essa função é thread-safe. Você deve sincronizar o uso simultâneo do `accelerator_view` objeto. Uso simultâneo de não-sincronizadas a `accelerator_view` objeto e a interface ID3D11Device bruta causa um comportamento indefinido.  
  
 O tempo de execução C++ AMP fornece informações detalhadas do erro em modo de depuração usando a camada D3D depurar se você usar o `D3D11_CREATE_DEVICE_DEBUG` sinalizador.  
  
  
##  <a name="a-named3daccesslocka--d3daccesslock-function"></a><a name="d3d_access_lock"></a>Função d3d_access_lock  
 Adquira um bloqueio em um accelerator_view para fins de segurança executar operações D3D em recursos compartilhados com o accelerator_view. O accelerator_view e todos os recursos de C++ AMP associados a essa accelerator_view internamente levar esse bloqueio ao executar operações e bloqueará enquanto outro thread mantém o bloqueio de acesso D3D. Esse bloqueio é não-recursiva: é um comportamento indefinido para chamar essa função a partir de um thread que já mantém o bloqueio. É um comportamento indefinido para executar operações de accelerator_view ou qualquer contêiner de dados associado a accelerator_view do segmento que retém o bloqueio de acesso D3D. Consulte também scoped_d3d_access_lock, uma classe de estilo RAII para um bloqueio de acesso com base no escopo D3D.  
  
```  
void __cdecl d3d_access_lock(accelerator_view& _Av);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Av`  
 Accelerator_view para bloquear.  
  
##  <a name="a-named3daccesstrylocka--d3daccesstrylock-function"></a><a name="d3d_access_try_lock"></a>Função d3d_access_try_lock  
 Tentativa de adquirir o bloqueio de acesso D3D em um accelerator_view sem bloqueio.  
  
```  
bool __cdecl d3d_access_try_lock(accelerator_view& _Av);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Av`  
 Accelerator_view para bloquear.  
  
### <a name="return-value"></a>Valor de retorno  
 True se o bloqueio tiver sido adquirido, ou falso se ele é mantido atualmente por outro thread.  
  
##  <a name="a-named3daccessunlocka--d3daccessunlock-function"></a><a name="d3d_access_unlock"></a>Função d3d_access_unlock  
 Libere o bloqueio D3D acesso a determinado accelerator_view. Se o thread de chamada não mantém o bloqueio de accelerator_view os resultados são indefinidos.  
  
```  
void __cdecl d3d_access_unlock(accelerator_view& _Av);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Av`  
 O accelerator_view para o qual o bloqueio for lançada.  
  
##  <a name="a-namefirstbithigha--firstbithigh-function"></a><a name="firstbithigh"></a>Função firstbithigh  
 Obtém o local do primeiro conjunto de bits em x, começando com o bit de ordem mais alta e migrando para o bit de ordem mais baixa.  
  
```  
inline int firstbithigh(int _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor inteiro  
  
### <a name="return-value"></a>Valor de retorno  
 O local do primeiro bit definido  
  
##  <a name="a-namefirstbitlowa--firstbitlow-function"></a><a name="firstbitlow"></a>Função firstbitlow  
 Obtém o local do primeiro conjunto de bits em x, começando com o bit de ordem mais baixa e trabalhando com o bit de ordem mais alta.  
  
```  
inline int firstbitlow(int _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor inteiro  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o local do primeiro conjunto de bits  
  
##  <a name="a-namegetbuffera--getbuffer-function"></a><a name="get_buffer"></a>Função get_buffer  
 Obter a interface de buffer do Direct3D subjacente na matriz especificada.  
  
```  
template<
    typename value_type,  
    int _Rank  
>  
IUnknown *get_buffer(
    const array<value_type, _Rank>& _Array)  ;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `value_type`  
 O tipo dos elementos na matriz.  
  
 `_Rank`  
 A classificação da matriz.  
  
 `_Array`  
 Uma matriz em uma accelerator_view Direct3D para que a interface de buffer do Direct3D subjacente é retornada.  
  
### <a name="return-value"></a>Valor de retorno  
 O ponteiro de interface IUnknown correspondente para o buffer do Direct3D subjacente da matriz.  
  
##  <a name="a-nameimaxa--imax-function"></a><a name="imax"></a>Função IMAX  
 Determinar o valor numérico máximo dos argumentos  
  
```  
inline int imax(
    int _X,  
    int _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor inteiro  
  
 `_Y`  
 Valor inteiro  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor numérico máximo dos argumentos  
  
##  <a name="a-nameimina--imin-function"></a><a name="imin"></a>Função imin  
 Determinar o valor numérico mínimo dos argumentos  
  
```  
inline int imin(
    int _X,  
    int _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor inteiro  
  
 `_Y`  
 Valor inteiro  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor numérico mínimo dos argumentos  
  
##  <a name="a-nameistimeoutdisableda--istimeoutdisabled-function"></a><a name="is_timeout_disabled"></a>Função is_timeout_disabled  
 Retorna um sinalizador booleano indicando se o tempo limite será desabilitada para o accelerator_view especificado. Isso corresponde ao sinalizador D3D11_CREATE_DEVICE_DISABLE_GPU_TIMEOUT para criação de dispositivo Direct3D.  
  
```  
bool __cdecl is_timeout_disabled(const accelerator_view& _Accelerator_view);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Accelerator_view`  
 O accelerator_view desativar a configuração para que o tempo limite será consultado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um sinalizador booleano indicando se o tempo limite será desabilitada para o accelerator_view especificado.  
  
##  <a name="a-namemada--mad-function"></a><a name="mad"></a>Função MAD  
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
 `_X`  
 O primeiro argumento especificado.  
  
 `_Y`  
 O segundo argumento especificado.  
  
 `_Z`  
 O terceiro argumento especificado.  
  
### <a name="return-value"></a>Valor de retorno  
 The result of `_X` * `_Y` + `_Z`.  
  
##  <a name="a-namemakearraya--makearray-function"></a><a name="make_array"></a>Função make_array  
 Crie uma matriz de um ponteiro de interface de buffer do Direct3D.  
  
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
 `value_type`  
 O tipo de elemento da matriz a ser criado.  
  
 `_Rank`  
 A classificação da matriz a ser criado.  
  
 `_Extent`  
 Uma extensão que descreve a forma da agregação de matriz.  
  
 `_Rv`  
 Uma exibição de acelerador D3D no qual a matriz deve ser criado.  
  
 `_D3D_buffer`  
 Ponteiro de interface IUnknown do buffer D3D para criar a matriz de.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma matriz criada com o buffer fornecido do Direct3D.  
  
##  <a name="a-namenoisea--noise-function"></a><a name="noise"></a>Função Noise  
 Gera um valor aleatório usando o algoritmo de ruído Perlin  
  
```  
inline float noise(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante da qual gerar ruído Perlin  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor de ruído Perlin a dentro de um intervalo entre -1 e 1  
  
##  <a name="a-nameradiansa--radians-function"></a><a name="radians"></a>Função radians  
 Converte x de graus em radianos  
  
```  
inline float radians(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna x convertido de graus em radianos  
  
##  <a name="a-namercpa--rcp-function"></a><a name="rcp"></a>Função rcp  
 Calcula a recíproca do argumento especificado usando uma aproximação rápida.  
  
```  
inline float rcp(float _X) restrict(amp);

 
inline double rcp(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 O valor para o qual calcular o recíproco.  
  
### <a name="return-value"></a>Valor de retorno  
 O recíproco do argumento especificado.  
  
##  <a name="a-namereversebitsa--reversebits-function"></a><a name="reversebits"></a>Função reversebits  
 Inverte a ordem dos bits em x  
  
```  
inline unsigned int reversebits(unsigned int _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor inteiro não assinado  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor com o bit de ordem invertido no x  
  
##  <a name="a-namesaturatea--saturate-function"></a><a name="saturate"></a>Função saturate  
 Clamps x dentro do intervalo de 0 a 1  
  
```  
inline float saturate(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna x fixado dentro do intervalo de 0 a 1  
  
##  <a name="a-namesigna--sign-function"></a><a name="sign"></a>Função Sign  
 Determina o sinal do argumento especificado.  
  
```  
inline int sign(int _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor inteiro  
  
### <a name="return-value"></a>Valor de retorno  
 O sinal do argumento.  
  
##  <a name="a-namesmoothstepa--smoothstep-function"></a><a name="smoothstep"></a>Função smoothstep  
 Retorna uma interpolação Hermite suave entre 0 e 1, se x está no intervalo [ min, máx].  
  
```  
inline float smoothstep(
    float _Min,  
    float _Max,  
    float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Min`  
 Valor de ponto flutuante  
  
 `_Max`  
 Valor de ponto flutuante  
  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna 0 se x for menor que min; 1 se x for maior que máx; Caso contrário, um valor entre 0 e 1 se x está no intervalo [ min, máx]  
  
##  <a name="a-namestepa--step-function"></a><a name="step"></a>Função Step  
 Compara dois valores, retornando 0 ou 1 com base em qual valor é maior  
  
```  
inline float step(
    float _Y,  
    float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Y`  
 Valor de ponto flutuante  
  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará 1 se o x for maior ou igual a y; Caso contrário, 0  
  
##  <a name="a-nameumaxa--umax-function"></a><a name="umax"></a>Função UMAX  
 Determinar o valor numérico máximo dos argumentos  
  
```  
inline unsigned int umax(
    unsigned int _X,  
    unsigned int _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor inteiro  
  
 `_Y`  
 Valor inteiro  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor numérico máximo dos argumentos  
  
##  <a name="a-nameumina--umin-function"></a><a name="umin"></a>Função umin  
 Determinar o valor numérico mínimo dos argumentos  
  
```  
inline unsigned int umin(
    unsigned int _X,  
    unsigned int _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor inteiro  
  
 `_Y`  
 Valor inteiro  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor numérico mínimo dos argumentos  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency:: Direct3D](concurrency-direct3d-namespace.md)

