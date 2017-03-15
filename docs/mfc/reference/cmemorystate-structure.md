---
title: Estrutura de CMemoryState | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMemoryState
dev_langs:
- C++
helpviewer_keywords:
- CMemoryState structure
- memory leaks, detecting
- detecting memory leaks
ms.assetid: 229d9de7-a6f3-4cc6-805b-5a9d9b1bfe1d
caps.latest.revision: 19
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 037c8f075a14346e3428c5e19bfda662c4f3c2b0
ms.lasthandoff: 02/25/2017

---
# <a name="cmemorystate-structure"></a>Estrutura CMemoryState
Fornece uma maneira conveniente para detectar vazamentos de memória em seu programa.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct CMemoryState  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMemoryState::CMemoryState](#cmemorystate)|Constrói uma estrutura de classe que controla os pontos de verificação de memória.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMemoryState::Checkpoint](#checkpoint)|Obtém um instantâneo (ponto de verificação) do estado atual de memória.|  
|[CMemoryState::Difference](#difference)|Calcula a diferença entre dois objetos do tipo `CMemoryState`.|  
|[CMemoryState::DumpAllObjectsSince](#dumpallobjectssince)|Despeja um resumo de todos os objetos alocados atualmente desde um ponto de verificação anterior.|  
|[CMemoryState::DumpStatistics](#dumpstatistics)|Imprime estatísticas de alocação de memória para um `CMemoryState` objeto.|  
  
## <a name="remarks"></a>Comentários  
 `CMemoryState`é uma estrutura e não tem uma classe base.  
  
 Um "vazamento de memória" ocorre quando a memória de um objeto é alocada no heap, mas não desalocada quando ele não é mais necessário. Tais vazamentos de memória, eventualmente, podem levar a erros de falta de memória. Há várias maneiras de alocar e desalocar a memória em seu programa:  
  
-   Usando o `malloc` /  **livre** família de funções da biblioteca de tempo de execução.  
  
-   Usando as funções de gerenciamento de memória de API do Windows, **LocalAlloc**/ **LocalFree** e **GlobalAlloc**/ **GlobalFree**.  
  
-   Usando o C++ **novo** e **excluir** operadores.  
  
 O `CMemoryState` diagnóstico apenas ajuda a detectar memória vazamentos causados quando a memória alocada usando o **novo** operador não é desalocado usando **excluir**. Dois grupos de funções de gerenciamento de memória são para programas não-c + + e misturando-as com **novo** e **excluir** no mesmo programa não é recomendado. Uma macro adicional, `DEBUG_NEW`, é fornecido para substituir o **novo** operador quando precisar de arquivo e rastreamento de linha-número de alocações de memória. `DEBUG_NEW`é usado sempre que você normalmente usaria o **novo** operador.  
  
 Assim como acontece com outros diagnósticos, o `CMemoryState` diagnósticos estão disponíveis apenas nas versões de depuração do seu programa. Uma versão de depuração deve ter o **Debug** constante definida.  
  
 Se você suspeitar que o seu programa tem um vazamento de memória, você pode usar o `Checkpoint`, **diferença**, e `DumpStatistics` funções para descobrir a diferença entre o estado da memória (objetos alocados) em dois pontos diferentes na execução do programa. Essa informação pode ser útil para determinar se uma função está limpando todos os objetos que aloca.  
  
 Se apenas saber onde ocorre o desequilíbrio da alocação e desalocação não fornecer informações suficientes, você pode usar o `DumpAllObjectsSince` função para despejar todos os objetos alocados desde a chamada anterior para `Checkpoint`. Este despejo mostra a ordem de alocação, o arquivo de origem e a linha em que o objeto foi alocado (se você estiver usando `DEBUG_NEW` para alocação) e a derivação de objeto, seu endereço e seu tamanho. `DumpAllObjectsSince`também chama cada objeto `Dump` função para fornecer informações sobre seu estado atual.  
  
 Para obter mais informações sobre como usar `CMemoryState` e outros diagnósticos, consulte [Depurando aplicativos MFC](/visualstudio/debugger/mfc-debugging-techniques).  
  
> [!NOTE]
>  Declarações de objetos do tipo `CMemoryState` e chamadas a funções de membro devem estar entre colchetes por `#if defined(_DEBUG)/#endif` diretivas. Isso faz com que o diagnóstico de memória a ser incluído somente em compilações do seu programa de depuração.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CMemoryState`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h  
  
##  <a name="a-namecheckpointa--cmemorystatecheckpoint"></a><a name="checkpoint"></a>CMemoryState::Checkpoint  
 Tira um instantâneo resumo de memória e o armazena no `CMemoryState` objeto.  
  
```  
void Checkpoint();
```  
  
### <a name="remarks"></a>Comentários  
 O `CMemoryState` funções de membro [diferença](#difference) e [DumpAllObjectsSince](#dumpallobjectssince) usar esses dados de instantâneo.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para a [CMemoryState](#cmemorystate) construtor.  
  
##  <a name="a-namecmemorystatea--cmemorystatecmemorystate"></a><a name="cmemorystate"></a>CMemoryState::CMemoryState  
 Constrói um vazio `CMemoryState` objeto deve ser preenchido pelo [ponto de verificação](#checkpoint) ou [diferença](#difference) função de membro.  
  
```  
CMemoryState();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_Utilities n º&18;](../../mfc/codesnippet/cpp/cmemorystate-structure_1.cpp)]  
  
##  <a name="a-namedifferencea--cmemorystatedifference"></a><a name="difference"></a>CMemoryState::Difference  
 Compara dois `CMemoryState` objetos e, em seguida, armazena a diferença no `CMemoryState` objeto.  
  
```  
BOOL Difference(
    const CMemoryState& oldState,   
    const CMemoryState& newState);
```  
  
### <a name="parameters"></a>Parâmetros  
 *oldState*  
 O estado de memória inicial conforme definido por uma `CMemoryState` ponto de verificação.  
  
 *newState*  
 O novo estado de memória conforme definido por uma `CMemoryState` ponto de verificação.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a memória de dois estados forem diferentes; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 [Ponto de verificação](#checkpoint) deve ter sido chamado para cada um dos dois parâmetros de estado de memória.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para a [CMemoryState](#cmemorystate) construtor.  
  
##  <a name="a-namedumpallobjectssincea--cmemorystatedumpallobjectssince"></a><a name="dumpallobjectssince"></a>CMemoryState::DumpAllObjectsSince  
 Chamadas de `Dump` função para todos os objetos de um tipo derivado da classe `CObject` que foram alocados (e ainda são alocados) desde a última [ponto de verificação](#checkpoint) chamar isso `CMemoryState` objeto.  
  
```  
void DumpAllObjectsSince() const;

 
```  
  
### <a name="remarks"></a>Comentários  
 Chamando `DumpAllObjectsSince` com uma inicializado `CMemoryState` objeto despejará todos os objetos atualmente na memória.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para a [CMemoryState](#cmemorystate) construtor.  
  
##  <a name="a-namedumpstatisticsa--cmemorystatedumpstatistics"></a><a name="dumpstatistics"></a>CMemoryState::DumpStatistics  
 Imprime um relatório de estatísticas de memória concisa de um `CMemoryState` objeto que é preenchido pelo [diferença](#difference) função de membro.  
  
```  
void DumpStatistics() const;

 
```  
  
### <a name="remarks"></a>Comentários  
 O relatório, que é impresso no [afxDump](http://msdn.microsoft.com/library/4b3cfa3f-fb75-456a-9d99-a5601acbcb11) dispositivo, mostra o seguinte:  
  
 Um exemplo de relatório fornece informações sobre o número (ou valor) de:  
  
-   blocos livres  
  
-   blocos normais  
  
-   Blocos de CRT  
  
-   Ignorar blocos  
  
-   blocos de cliente  
  
-   máximo de memória usada pelo programa a qualquer momento (em bytes)  
  
-   memória total usada atualmente pelo programa (em bytes)  
  
 Blocos livres são o número de blocos cuja desalocação foi atrasada se `afxMemDF` foi definido como **delayFreeMemDF**. Para obter mais informações, consulte [afxMemDF](diagnostic-services.md#afxmemdf), na seção "Macros e globais MFC". Consulte [tipos de blocos na Heap de depuração](http://msdn.microsoft.com/en-us/db2e7f62-0679-4b39-a23f-26f2c2f407c5) para obter mais informações sobre esses tipos de bloco.  
  
### <a name="example"></a>Exemplo  
  O código a seguir deve ser colocado em *NomeDoProjeto*App. cpp. Defina as seguintes variáveis globais:  
  
 [!code-cpp[40 NVC_MFC_Utilities](../../mfc/codesnippet/cpp/cmemorystate-structure_2.cpp)]  
  
 Na `InitInstance` function, adicione a linha:  
  
 [!code-cpp[41 NVC_MFC_Utilities](../../mfc/codesnippet/cpp/cmemorystate-structure_3.cpp)]  
  
 Adicionar um manipulador para o `ExitInstance` de função e use o seguinte código:  
  
 [!code-cpp[NVC_MFC_Utilities&42;](../../mfc/codesnippet/cpp/cmemorystate-structure_4.cpp)]  
  
 Agora você pode executar o programa no modo de depuração para ver a saída de `DumpStatistics` função.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)




