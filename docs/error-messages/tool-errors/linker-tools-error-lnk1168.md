---
title: Ferramentas de vinculador LNK1168 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK1168
dev_langs: C++
helpviewer_keywords: LNK1168
ms.assetid: 97ead151-fd99-46fe-9a1d-7e84dc0b8cc8
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 12dfce4243f0872735158df7ccd81b7c6e29efc8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk1168"></a>Erro das Ferramentas de Vinculador LNK1168
não foi possível abrir filename para escrita  
  
 O vinculador não pode gravar em `filename`. O arquivo pode estar em uso e em seu identificador de arquivo bloqueado por outro processo, ou você pode não ter permissão de gravação para o arquivo, ou para o diretório ou o compartilhamento de rede em que ele está localizado. Esse erro é causado por uma condição transitória – por exemplo, um bloqueio mantido por um programa antivírus, um processo de indexação de pesquisa de arquivo ou um atraso na liberação de um bloqueio mantido pelo sistema de compilação do [!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)].  
  
 Para corrigir esse problema, verifique se o identificador do arquivo `filename` não está bloqueado e se você tem permissão de gravação para o arquivo. Se for um executável, verifique se não está em execução.  
  
 Você pode usar os utilitários do Windows SysInternals [tratar](http://technet.microsoft.com/sysinternals/bb896655.aspx) ou [Process Explorer](http://technet.microsoft.com/sysinternals/bb896653) para determinar qual processo tem um arquivo de identificador de bloqueio no `filename`. Você também pode usar o Process Explorer para liberar bloqueios em identificadores de arquivos abertos. Para obter informações sobre como usar esses utilitários, consulte os arquivos da Ajuda que os acompanham.  
  
 Se o arquivo estiver bloqueado por um programa antivírus, você poderá resolver esse problema excluindo os diretórios de saída de compilação de verificação automática pelo programa antivírus. Os verificadores antivírus são disparados frequentemente pela criação de novos arquivos no sistema de arquivos e mantêm bloqueios em arquivos durante a análise. Consulte a documentação do programa antivírus para obter detalhes sobre como excluir diretórios específicos da verificação.  
  
 Se o arquivo for bloqueada por um serviço de indexação de pesquisa, você poderá resolver esse problema excluindo os diretórios de saída de compilação de indexação automática. Consulte a documentação do serviço de indexação para obter mais informações. Para alterar a serviço de indexação de pesquisa do Windows, use **opções de indexação** nas janelas **painel de controle**. Para obter mais informações, consulte [Windows melhorar pesquisas usando o índice: perguntas frequentes](http://windows.microsoft.com/en-us/windows/improve-windows-searches-using-index-faq#1TC=windows-7).  
  
 Se o executável não puder ser substituído pelo processo de compilação, ele poderá estar bloqueado pelo Explorador de Arquivos. Se o **experiência de aplicativo** serviço foi desabilitado, o Explorador de arquivos pode manter um bloqueio de identificador de arquivo executável por um longo período. Para corrigir esse problema, execute **services.msc** e, em seguida, abra o **propriedades** caixa de diálogo para o **experiência de aplicativo** serviço. Alterar o **o tipo de inicialização** de **desabilitado** para **Manual**.  
  
## <a name="see-also"></a>Consulte também  
 [Você pode receber um "erro PRJ0008" ou "Erro Fatal LNK1168" mensagem de erro ao tentar criar uma solução ou um projeto do ActiveX no Visual C++](http://support.microsoft.com/kb/308358)