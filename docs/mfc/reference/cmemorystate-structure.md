---
title: Estrutura de CMemoryState | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMemoryState
dev_langs:
- C++
helpviewer_keywords:
- CMemoryState structure [MFC]
- memory leaks [MFC], detecting
- detecting memory leaks [MFC]
ms.assetid: 229d9de7-a6f3-4cc6-805b-5a9d9b1bfe1d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 20f4c2d7d33d07a5eca5a980c376056c3fe68e2d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmemorystate-structure"></a>Estrutura CMemoryState
Fornece uma maneira conveniente para detectar perdas de memória em seu programa.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct CMemoryState  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMemoryState::CMemoryState](#cmemorystate)|Constrói uma estrutura de classe que controla os pontos de verificação de memória.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMemoryState::Checkpoint](#checkpoint)|Obtém um instantâneo (ponto de verificação) do estado atual de memória.|  
|[CMemoryState::Difference](#difference)|Calcula a diferença entre dois objetos do tipo `CMemoryState`.|  
|[CMemoryState::DumpAllObjectsSince](#dumpallobjectssince)|Um resumo de todos os objetos atualmente alocados de despejos de memória desde um ponto de verificação anterior.|  
|[CMemoryState::DumpStatistics](#dumpstatistics)|Imprime estatísticas de alocação de memória para um `CMemoryState` objeto.|  
  
## <a name="remarks"></a>Comentários  
 `CMemoryState`é uma estrutura e não tem uma classe base.  
  
 Um "vazamento de memória" ocorre quando a memória de um objeto é alocada no heap, mas não é desalocada quando ele não é mais necessário. Tais vazamentos de memória, eventualmente, podem levar a erros de falta de memória. Há várias maneiras de alocar e desalocar memória em seu programa:  
  
-   Usando o `malloc` /  **livre** família de funções da biblioteca de tempo de execução.  
  
-   Usando as funções de gerenciamento de memória de API do Windows, **LocalAlloc**/ **LocalFree** e **GlobalAlloc**/ **GlobalFree** .  
  
-   Usando o C++ **novo** e **excluir** operadores.  
  
 O `CMemoryState` diagnóstico apenas ajuda a detectar memória vazamentos causados quando a memória alocada usando o **novo** operador não é desalocado usando **excluir**. Dois grupos de funções de gerenciamento de memória são para programas não C++ e mesclando-as com **novo** e **excluir** no mesmo programa não é recomendado. Uma macro adicional, `DEBUG_NEW`, é fornecido para substituir o **novo** operador quando precisar de arquivo e o controle de linha-número de alocações de memória. `DEBUG_NEW`é usado sempre que normalmente usaria o **novo** operador.  
  
 Assim como acontece com outros diagnóstico, o `CMemoryState` diagnóstico só está disponível em versões de depuração do seu programa. Uma versão de depuração deve ter o **Debug** constante definida.  
  
 Se você suspeitar que o programa tiver um vazamento de memória, você pode usar o `Checkpoint`, **diferença**, e `DumpStatistics` funções para descobrir a diferença entre o estado de memória (objetos alocados) em duas diferentes pontos no programa execução. Essa informação pode ser útil para determinar se uma função está limpando todos os objetos que aloca.  
  
 Se simplesmente saber onde ocorre o desequilíbrio da alocação e desalocação não fornecer informações suficientes, você pode usar o `DumpAllObjectsSince` função para despejar todos os objetos alocados desde a chamada anterior para `Checkpoint`. Este despejo mostra a ordem de alocação, o arquivo de origem e a linha em que o objeto foi alocado (se você estiver usando `DEBUG_NEW` para alocação) e a derivação de objeto, seu endereço e seu tamanho. `DumpAllObjectsSince`também chama cada objeto `Dump` função para fornecer informações sobre seu estado atual.  
  
 Para obter mais informações sobre como usar `CMemoryState` e outros diagnósticos, consulte [aplicativos do MFC de depuração](/visualstudio/debugger/mfc-debugging-techniques).  
  
> [!NOTE]
>  Declarações de objetos do tipo `CMemoryState` e chamadas para funções de membro devem ser agrupadas por `#if defined(_DEBUG)/#endif` diretivas. Isso faz com que o diagnóstico de memória a ser incluído somente em depuração compilações do seu programa.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CMemoryState`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX  
  
##  <a name="checkpoint"></a>CMemoryState::Checkpoint  
 Tira um instantâneo resumo de memória e o armazena na `CMemoryState` objeto.  
  
```  
void Checkpoint();
```  
  
### <a name="remarks"></a>Comentários  
 O `CMemoryState` funções de membro [diferença](#difference) e [DumpAllObjectsSince](#dumpallobjectssince) usar esses dados de instantâneo.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para o [CMemoryState](#cmemorystate) construtor.  
  
##  <a name="cmemorystate"></a>CMemoryState::CMemoryState  
 Constrói um vazio `CMemoryState` objeto deve ser preenchido pelo [ponto de verificação](#checkpoint) ou [diferença](#difference) função de membro.  
  
```  
CMemoryState();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_Utilities#18](../../mfc/codesnippet/cpp/cmemorystate-structure_1.cpp)]  
  
##  <a name="difference"></a>CMemoryState::Difference  
 Compara dois `CMemoryState` objetos, em seguida, armazena a diferença em isso `CMemoryState` objeto.  
  
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
  Consulte o exemplo para o [CMemoryState](#cmemorystate) construtor.  
  
##  <a name="dumpallobjectssince"></a>CMemoryState::DumpAllObjectsSince  
 Chamadas de `Dump` função para todos os objetos de um tipo derivado da classe `CObject` que foram alocados (e ainda são alocados) desde a última [ponto de verificação](#checkpoint) chamar para este `CMemoryState` objeto.  
  
```  
void DumpAllObjectsSince() const;

 
```  
  
### <a name="remarks"></a>Comentários  
 Chamando `DumpAllObjectsSince` com um não inicializada `CMemoryState` objeto será despejar todos os objetos em memória no momento.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para o [CMemoryState](#cmemorystate) construtor.  
  
##  <a name="dumpstatistics"></a>CMemoryState::DumpStatistics  
 Imprime um relatório de estatísticas de memória concisa de um `CMemoryState` objeto que é preenchido pelo [diferença](#difference) função de membro.  
  
```  
void DumpStatistics() const;

 
```  
  
### <a name="remarks"></a>Comentários  
 O relatório, que é impresso no [afxDump](diagnostic-services.md#afxdump) dispositivo, mostra o seguinte:  
  
 Um exemplo de relatório fornece informações sobre o número (ou quantidade) de:  
  
-   blocos livres  
  
-   blocos normais  
  
-   Blocos de CRT  
  
-   Ignorar blocos  
  
-   blocos de cliente  
  
-   máximo de memória usada pelo programa a qualquer momento (em bytes)  
  
-   memória total usada no momento pelo programa (em bytes)  
  
 Blocos livres são o número de blocos cuja desalocação foi atrasada se `afxMemDF` foi definida como **delayFreeMemDF**. Para obter mais informações, consulte [afxMemDF](diagnostic-services.md#afxmemdf), na seção "Macros e globais MFC". Consulte [tipos de blocos no Heap de depuração](http://msdn.microsoft.com/en-us/db2e7f62-0679-4b39-a23f-26f2c2f407c5) para obter mais informações sobre esses bloquear tipos.  
  
### <a name="example"></a>Exemplo  
  O código a seguir deve ser colocado em *NomeDoProjeto*App.cpp. Defina as seguintes variáveis globais:  
  
 [!code-cpp[NVC_MFC_Utilities#40](../../mfc/codesnippet/cpp/cmemorystate-structure_2.cpp)]  
  
 No `InitInstance` funcionar, adicione a linha:  
  
 [!code-cpp[NVC_MFC_Utilities#41](../../mfc/codesnippet/cpp/cmemorystate-structure_3.cpp)]  
  
 Adicionar um manipulador para o `ExitInstance` de função e use o seguinte código:  
  
 [!code-cpp[NVC_MFC_Utilities#42](../../mfc/codesnippet/cpp/cmemorystate-structure_4.cpp)]  
  
 Agora você pode executar o programa em modo de depuração para ver a saída do `DumpStatistics` função.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



