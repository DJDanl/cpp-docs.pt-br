---
title: "Relatório de - Qvec (nível de emissão de relatórios do Vetorizador automático) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 4778c9a3-0692-4085-9b05-1bfeadf4c74a
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 43c9a182046ff148621151107a98932cc39835f2
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="qvec-report-auto-vectorizer-reporting-level"></a>/Qvec-report (nível de relatórios do vetorizador automático)
Habilita o recurso de relatório do compilador [Vetorizador automático](../../parallel/auto-parallelization-and-auto-vectorization.md) e especifica o nível de mensagens informativas para saída durante a compilação.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Qvec-report:{1}{2}  
```  
  
## <a name="remarks"></a>Comentários  
 **/Qvec-Report-relatório: 1**  
 Gera uma mensagem informativa para loops são vetorizado.  
  
 **/Qvec-Report-relatório: 2**  
 Gera uma mensagem informativa para loops são vetorizadas em loops não vetorizadas, junto com um código de motivo.  
  
 Para obter informações sobre códigos de motivo e mensagens, consulte [mensagens do Vetorizador e Paralelizador](../../error-messages/tool-errors/vectorizer-and-parallelizer-messages.md).  
  
### <a name="to-set-the-qvec-report-compiler-option-in-visual-studio"></a>Para definir a opção de compilador /Qvec-report no Visual Studio  
  
1.  No **Gerenciador de Soluções**, abra o menu de atalho para o projeto e escolha **Propriedades**.  
  
2.  No **páginas de propriedade** caixa de diálogo **C/C++**, selecione **linha de comando**.  
  
3.  No **opções adicionais** , digite `/Qvec-report:1` ou `/Qvec-report:2`.  
  
### <a name="to-set-the-qvec-report-compiler-option-programmatically"></a>Para definir a opção de compilador /Qvec-report programaticamente  
  
-   Use o exemplo de código em <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [/Q opções (operações de nível baixo)](../../build/reference/q-options-low-level-operations.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [Programação paralela em código nativo](http://go.microsoft.com/fwlink/p/?linkid=263662)