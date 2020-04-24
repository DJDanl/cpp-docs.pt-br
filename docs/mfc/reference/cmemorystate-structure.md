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
ms.openlocfilehash: 94a2fb65a9a3030f9dc683d0eb30f476b9de1cad
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81752606"
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
|[cMemoryState::CMemoryState](#cmemorystate)|Constrói uma estrutura de classe que controla os pontos de verificação de memória.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMemoryState::Checkpoint](#checkpoint)|Obtém um instantâneo (ponto de verificação) do estado atual da memória.|
|[CMemoryState::Differência](#difference)|Calcula a diferença entre `CMemoryState`dois objetos do tipo .|
|[CMemoryState::DumpAllObjectsSince](#dumpallobjectssince)|Despeja um resumo de todos os objetos atualmente alocados desde um ponto de verificação anterior.|
|[CMemoryState::DumpStatistics](#dumpstatistics)|Imprime estatísticas de `CMemoryState` alocação de memória para um objeto.|

## <a name="remarks"></a>Comentários

`CMemoryState`é uma estrutura e não tem uma classe base.

Um "vazamento de memória" ocorre quando a memória de um objeto é alocada no heap, mas não desalocada quando não é mais necessária. Esses vazamentos de memória podem eventualmente levar a erros fora da memória. Existem várias maneiras de alocar e desalocar a memória em seu programa:

- Usando `malloc` /  `free` a família de funções da biblioteca de tempo de execução.

- Usando as funções de gerenciamento `LocalAlloc` /  `LocalFree` `GlobalAlloc` / de memória do Windows API e `GlobalFree`.

- Usando os operadores **c++ novos** e **exclusão.**

Os `CMemoryState` diagnósticos só ajudam a detectar vazamentos de memória causados quando a memória alocada usando o **novo** operador não é desalocada usando **excluir**. Os outros dois grupos de funções de gerenciamento de memória são para programas não-C++ e misturá-los com **novos** e **excluídos** no mesmo programa não é recomendado. Uma macro adicional, DEBUG_NEW, é fornecida para substituir o **novo** operador quando você precisar de rastreamento de arquivos e números de linha de alocações de memória. DEBUG_NEW é usado sempre que você normalmente usa o **novo** operador.

Assim como em outros `CMemoryState` diagnósticos, os diagnósticos só estão disponíveis em versões de depuração do seu programa. Uma versão dedepuradeve ter o _DEBUG constante definido.

Se você suspeitar que seu programa tem `Checkpoint` `Difference`um `DumpStatistics` vazamento de memória, você pode usar o , e funções para descobrir a diferença entre o estado de memória (objetos alocados) em dois pontos diferentes na execução do programa. Essas informações podem ser úteis para determinar se uma função está limpando todos os objetos que aloca.

Se simplesmente saber onde o desequilíbrio na alocação e desalocação ocorre não fornecer informações suficientes, você pode usar a `DumpAllObjectsSince` função para despejar todos os objetos alocados desde a chamada anterior para `Checkpoint`. Este dump mostra a ordem de alocação, o arquivo de origem e a linha onde o objeto foi alocado (se você estiver usando DEBUG_NEW para alocação), e a derivação do objeto, seu endereço e seu tamanho. `DumpAllObjectsSince`também chama a `Dump` função de cada objeto para fornecer informações sobre seu estado atual.

Para obter mais informações `CMemoryState` sobre como usar e outros diagnósticos, consulte [Depuração de Aplicativos MFC](/visualstudio/debugger/mfc-debugging-techniques).

> [!NOTE]
> As declarações de `CMemoryState` objetos de tipo e chamadas `#if defined(_DEBUG)/#endif` para funções de membros devem ser orientadas por diretivas. Isso faz com que o diagnóstico de memória seja incluído apenas na depuração de compilações do seu programa.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CMemoryState`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="cmemorystatecheckpoint"></a><a name="checkpoint"></a>CMemoryState::Checkpoint

Pega um resumo instantâneo da memória e `CMemoryState` armazena-a neste objeto.

```cpp
void Checkpoint();
```

### <a name="remarks"></a>Comentários

O `CMemoryState` membro funciona [Difference](#difference) e [DumpAllObjectsDesde](#dumpallobjectssince) usar esses dados de snapshot.

### <a name="example"></a>Exemplo

  Veja o exemplo do construtor [CMemoryState.](#cmemorystate)

## <a name="cmemorystatecmemorystate"></a><a name="cmemorystate"></a>cMemoryState::CMemoryState

Constrói um `CMemoryState` objeto vazio que deve ser preenchido pela função [Defazer ponto](#checkpoint) de verificação ou [diferença.](#difference)

```
CMemoryState();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#18](../../mfc/codesnippet/cpp/cmemorystate-structure_1.cpp)]

## <a name="cmemorystatedifference"></a><a name="difference"></a>CMemoryState::Differência

Compara `CMemoryState` dois objetos e armazena `CMemoryState` a diferença neste objeto.

```
BOOL Difference(
    const CMemoryState& oldState,
    const CMemoryState& newState);
```

### <a name="parameters"></a>Parâmetros

*Oldstate*<br/>
O estado inicial de `CMemoryState` memória definido por um ponto de verificação.

*newState*<br/>
O novo estado de `CMemoryState` memória como definido por um ponto de verificação.

### <a name="return-value"></a>Valor retornado

Não zero se os dois estados de memória forem diferentes; caso contrário, 0.

### <a name="remarks"></a>Comentários

O ponto de [verificação](#checkpoint) deve ter sido chamado para cada um dos dois parâmetros de estado de memória.

### <a name="example"></a>Exemplo

  Veja o exemplo do construtor [CMemoryState.](#cmemorystate)

## <a name="cmemorystatedumpallobjectssince"></a><a name="dumpallobjectssince"></a>CMemoryState::DumpAllObjectsSince

Chama `Dump` a função para todos os objetos de um tipo derivado da classe `CObject` que foram alocados (e ainda estão alocados) desde a última chamada de [Checkpoint](#checkpoint) para este `CMemoryState` objeto.

```cpp
void DumpAllObjectsSince() const;
```

### <a name="remarks"></a>Comentários

A `DumpAllObjectsSince` chamada com `CMemoryState` um objeto não inicializado despejará todos os objetos atualmente na memória.

### <a name="example"></a>Exemplo

  Veja o exemplo do construtor [CMemoryState.](#cmemorystate)

## <a name="cmemorystatedumpstatistics"></a><a name="dumpstatistics"></a>CMemoryState::DumpStatistics

Imprime um relatório de estatísticas `CMemoryState` de memória concisa de um objeto preenchido pela função [membro Diferença.](#difference)

```cpp
void DumpStatistics() const;
```

### <a name="remarks"></a>Comentários

O relatório, que é impresso no dispositivo [afxDump,](diagnostic-services.md#afxdump) mostra o seguinte:

Um relatório de amostra fornece informações sobre o número (ou quantidade) de:

- blocos livres

- blocos normais

- Blocos CRT

- ignorar blocos

- blocos de cliente

- memória máxima usada pelo programa em qualquer momento (em bytes)

- memória total atualmente usada pelo programa (em bytes)

Blocos livres são o número de blocos cuja desalocação foi adiada se `afxMemDF` foi definida para `delayFreeMemDF`. Para obter mais informações, consulte [afxMemDF](diagnostic-services.md#afxmemdf), na seção "MFC Macros and Globals".

### <a name="example"></a>Exemplo

  O seguinte código deve ser colocado em *projname*App.cpp. Defina as seguintes variáveis globais:

[!code-cpp[NVC_MFC_Utilities#40](../../mfc/codesnippet/cpp/cmemorystate-structure_2.cpp)]

Na `InitInstance` função, adicione a linha:

[!code-cpp[NVC_MFC_Utilities#41](../../mfc/codesnippet/cpp/cmemorystate-structure_3.cpp)]

Adicione um manipulador `ExitInstance` para a função e use o seguinte código:

[!code-cpp[NVC_MFC_Utilities#42](../../mfc/codesnippet/cpp/cmemorystate-structure_4.cpp)]

Agora você pode executar o programa no modo `DumpStatistics` Debug para ver a saída da função.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
