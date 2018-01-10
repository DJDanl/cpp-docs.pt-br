---
title: "Relatório de - Qpar (nível de emissão de relatórios do Paralelizador automático) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 562673b9-02da-4bf8-bb64-70bc25ef4651
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 70ae055d69341cc773b8b40ed1111b65ba5683cf
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="qpar-report-auto-parallelizer-reporting-level"></a>/Qpar-report (nível de relatórios do paralelizador automático)
Habilita o recurso de relatório do compilador [Paralelizador automático](../../parallel/auto-parallelization-and-auto-vectorization.md) e especifica o nível de mensagens informativas para saída durante a compilação.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Qpar-report:{1}{2}  
```  
  
## <a name="remarks"></a>Comentários  
 **/Qpar-relatório: 1**  
 Gera uma mensagem informativa para loops que são colocados em paralelo.  
  
 **/Qpar-relatório: 2**  
 Gera uma mensagem informativa para loops que são colocados em paralelo e também para loops que não são colocados em paralelo, juntamente com um código de motivo.  
  
 As mensagens são relatadas para stdout. Se nenhuma mensagem informativa for relatada, o código não contém nenhum loops ou o nível de relatório não foi definido para loops de relatório que não são colocados em paralelo. Para obter mais informações sobre códigos de motivo e mensagens, consulte [mensagens do Vetorizador e Paralelizador](../../error-messages/tool-errors/vectorizer-and-parallelizer-messages.md).  
  
### <a name="to-set-the-qpar-report-compiler-option-in-visual-studio"></a>Para definir a opção de compilador /Qpar-report no Visual Studio  
  
1.  No **Gerenciador de Soluções**, abra o menu de atalho para o projeto e escolha **Propriedades**.  
  
2.  No **páginas de propriedade** caixa de diálogo **C/C++**, selecione **linha de comando**.  
  
3.  No **opções adicionais** , digite `/Qpar-report:1` ou `/Qpar-report:2`.  
  
### <a name="to-set-the-qpar-report-compiler-option-programmatically"></a>Para definir a opção do compilador /Qpar-report programaticamente  
  
-   Use o exemplo de código em <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [/Q opções (operações de nível baixo)](../../build/reference/q-options-low-level-operations.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [Programação paralela em código nativo](http://go.microsoft.com/fwlink/p/?linkid=263662)