---
title: Estrutura CMemoryState
ms.date: 11/04/2016
f1_keywords:
- CMemoryState
helpviewer_keywords:
- CMemoryState structure [MFC]
- memory leaks [MFC], detecting
- detecting memory leaks [MFC]
ms.assetid: 229d9de7-a6f3-4cc6-805b-5a9d9b1bfe1d
ms.openlocfilehash: 823d424620e205d14f247a147bbf7dcb40a626b9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222908"
---
# <a name="cmemorystate-structure"></a>Estrutura CMemoryState

Fornece uma maneira conveniente de detectar vazamentos de memória em seu programa.

## <a name="syntax"></a>Sintaxe

```
struct CMemoryState
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMemoryState::CMemoryState](#cmemorystate)|Constrói uma estrutura semelhante a uma classe que controla pontos de verificação de memória.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMemoryState:: ponto de verificação](#checkpoint)|Obtém um instantâneo (ponto de verificação) do estado da memória atual.|
|[CMemoryState::D ifference](#difference)|Computa a diferença entre dois objetos do tipo `CMemoryState` .|
|[CMemoryState::D umpAllObjectsSince](#dumpallobjectssince)|Despeja um resumo de todos os objetos atualmente alocados desde um ponto de verificação anterior.|
|[CMemoryState::D umpStatistics](#dumpstatistics)|Imprime as estatísticas de alocação de memória de um `CMemoryState` objeto.|

## <a name="remarks"></a>Comentários

`CMemoryState`é uma estrutura e não tem uma classe base.

Uma "perda de memória" ocorre quando a memória de um objeto é alocada no heap, mas não desalocada quando não é mais necessária. Esses vazamentos de memória podem resultar em erros de memória insuficiente. Há várias maneiras de alocar e desalocar memória em seu programa:

- Usando a `malloc` /  `free` família de funções da biblioteca de tempo de execução.

- Usando as funções de gerenciamento de memória da API do Windows `LocalAlloc` /  `LocalFree` e o `GlobalAlloc` /  `GlobalFree` .

- Usando o C++ **`new`** e os **`delete`** operadores.

O `CMemoryState` diagnóstico só ajuda a detectar vazamentos de memória causados quando a memória alocada usando o **`new`** operador não é desalocada usando **`delete`** . Os outros dois grupos de funções de gerenciamento de memória são para programas não C + +, e a combinação deles com **`new`** e **`delete`** no mesmo programa não é recomendada. Uma macro adicional, DEBUG_NEW, é fornecida para substituir o **`new`** operador quando você precisa de controle de arquivo e de número de linha de alocações de memória. DEBUG_NEW é usado sempre que você normalmente usaria o **`new`** operador.

Assim como ocorre com outros diagnósticos, os `CMemoryState` diagnósticos só estão disponíveis em versões de depuração do seu programa. Uma versão de depuração deve ter a constante de _DEBUG definida.

Se você suspeitar que seu programa tem um vazamento de memória, poderá usar as `Checkpoint` `Difference` funções, e `DumpStatistics` para descobrir a diferença entre o estado da memória (objetos alocados) em dois pontos diferentes na execução do programa. Essas informações podem ser úteis para determinar se uma função está limpando todos os objetos alocados.

Se simplesmente saber onde o desequilíbrio na alocação e desalocação ocorre não fornece informações suficientes, você pode usar a `DumpAllObjectsSince` função para despejar todos os objetos alocados desde a chamada anterior para `Checkpoint` . Esse despejo mostra a ordem de alocação, o arquivo de origem e a linha em que o objeto foi alocado (se você estiver usando DEBUG_NEW para alocação) e a derivação do objeto, seu endereço e seu tamanho. `DumpAllObjectsSince`também chama a função de cada objeto `Dump` para fornecer informações sobre seu estado atual.

Para obter mais informações sobre como usar o `CMemoryState` e outros diagnósticos, consulte [Debugging MFC Applications](/visualstudio/debugger/mfc-debugging-techniques).

> [!NOTE]
> Declarações de objetos do tipo `CMemoryState` e chamadas para funções de membro devem ser inseridas por `#if defined(_DEBUG)/#endif` diretivas. Isso faz com que o diagnóstico de memória seja incluído somente na depuração de compilações do seu programa.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CMemoryState`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="cmemorystatecheckpoint"></a><a name="checkpoint"></a>CMemoryState:: ponto de verificação

Tira um resumo do instantâneo da memória e o armazena nesse `CMemoryState` objeto.

```cpp
void Checkpoint();
```

### <a name="remarks"></a>Comentários

A `CMemoryState` [diferença](#difference) entre funções de membro e [DumpAllObjectsSince](#dumpallobjectssince) usam esses dados de instantâneo.

### <a name="example"></a>Exemplo

  Consulte o exemplo para o construtor [CMemoryState](#cmemorystate) .

## <a name="cmemorystatecmemorystate"></a><a name="cmemorystate"></a>CMemoryState::CMemoryState

Constrói um objeto vazio `CMemoryState` que deve ser preenchido pela função de membro de [ponto de verificação](#checkpoint) ou [diferença](#difference) .

```
CMemoryState();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#18](../../mfc/codesnippet/cpp/cmemorystate-structure_1.cpp)]

## <a name="cmemorystatedifference"></a><a name="difference"></a>CMemoryState::D ifference

Compara dois `CMemoryState` objetos e, em seguida, armazena a diferença nesse `CMemoryState` objeto.

```
BOOL Difference(
    const CMemoryState& oldState,
    const CMemoryState& newState);
```

### <a name="parameters"></a>parâmetros

*oldState*<br/>
O estado de memória inicial, conforme definido por um `CMemoryState` ponto de verificação.

*newState*<br/>
O novo estado de memória, conforme definido por um `CMemoryState` ponto de verificação.

### <a name="return-value"></a>Valor retornado

Diferente de zero se os dois Estados de memória forem diferentes; caso contrário, 0.

### <a name="remarks"></a>Comentários

O [ponto de verificação](#checkpoint) deve ter sido chamado para cada um dos dois parâmetros de estado de memória.

### <a name="example"></a>Exemplo

  Consulte o exemplo para o construtor [CMemoryState](#cmemorystate) .

## <a name="cmemorystatedumpallobjectssince"></a><a name="dumpallobjectssince"></a>CMemoryState::D umpAllObjectsSince

Chama a `Dump` função para todos os objetos de um tipo derivado da classe `CObject` que foram alocados (e ainda estão alocados) desde a última chamada de [ponto de verificação](#checkpoint) para esse `CMemoryState` objeto.

```cpp
void DumpAllObjectsSince() const;
```

### <a name="remarks"></a>Comentários

Chamar `DumpAllObjectsSince` com um objeto não inicializado `CMemoryState` despejará todos os objetos atualmente na memória.

### <a name="example"></a>Exemplo

  Consulte o exemplo para o construtor [CMemoryState](#cmemorystate) .

## <a name="cmemorystatedumpstatistics"></a><a name="dumpstatistics"></a>CMemoryState::D umpStatistics

Imprime um relatório de estatísticas de memória concisa de um `CMemoryState` objeto que é preenchido pela função de membro de [diferença](#difference) .

```cpp
void DumpStatistics() const;
```

### <a name="remarks"></a>Comentários

O relatório, que é impresso no dispositivo [afxDump](diagnostic-services.md#afxdump) , mostra o seguinte:

Um relatório de exemplo fornece informações sobre o número (ou quantidade) de:

- blocos livres

- blocos normais

- Blocos CRT

- Ignorar blocos

- blocos de cliente

- memória máxima usada pelo programa a qualquer momento (em bytes)

- memória total usada atualmente pelo programa (em bytes)

Blocos livres são o número de blocos cuja desalocação foi atrasada se `afxMemDF` foi definido como `delayFreeMemDF` . Para obter mais informações, consulte [afxMemDF](diagnostic-services.md#afxmemdf), na seção "macros MFC e globais".

### <a name="example"></a>Exemplo

  O código a seguir deve ser colocado em *ProjName*app. cpp. Defina as seguintes variáveis globais:

[!code-cpp[NVC_MFC_Utilities#40](../../mfc/codesnippet/cpp/cmemorystate-structure_2.cpp)]

Na `InitInstance` função, adicione a linha:

[!code-cpp[NVC_MFC_Utilities#41](../../mfc/codesnippet/cpp/cmemorystate-structure_3.cpp)]

Adicione um manipulador para a `ExitInstance` função e use o seguinte código:

[!code-cpp[NVC_MFC_Utilities#42](../../mfc/codesnippet/cpp/cmemorystate-structure_4.cpp)]

Agora você pode executar o programa no modo de depuração para ver a saída da `DumpStatistics` função.

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)
