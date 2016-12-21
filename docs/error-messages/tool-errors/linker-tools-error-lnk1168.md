---
title: "Erro das Ferramentas de Vinculador LNK1168 | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "LNK1168"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK1168"
ms.assetid: 97ead151-fd99-46fe-9a1d-7e84dc0b8cc8
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK1168
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não foi possível abrir filename para escrita  
  
 O vinculador não pode gravar em `filename`.  O arquivo pode estar em uso e em seu identificador de arquivo bloqueado por outro processo, ou você pode não ter permissão de gravação para o arquivo, ou para o diretório ou o compartilhamento de rede em que ele está localizado.  Esse erro é causado por uma condição transitória – por exemplo, um bloqueio mantido por um programa antivírus, um processo de indexação de pesquisa de arquivo ou um atraso na liberação de um bloqueio mantido pelo sistema de compilação do [!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)].  
  
 Para corrigir esse problema, verifique se o identificador do arquivo `filename` não está bloqueado e se você tem permissão de gravação para o arquivo.  Se for um executável, verifique se não está em execução.  
  
 Você pode usar os utilitários do Windows SysInternals [tratar](http://technet.microsoft.com/sysinternals/bb896655.aspx) ou [Process Explorer](http://technet.microsoft.com/sysinternals/bb896653) para determinar qual processo tem um arquivo de bloqueio de identificador `filename`.  Você também pode usar o Process Explorer para liberar bloqueios em identificadores de arquivos abertos.  Para obter informações sobre como usar esses utilitários, consulte os arquivos da Ajuda que os acompanham.  
  
 Se o arquivo estiver bloqueado por um programa antivírus, você poderá resolver esse problema excluindo os diretórios de saída de compilação de verificação automática pelo programa antivírus.  Os verificadores antivírus são disparados frequentemente pela criação de novos arquivos no sistema de arquivos e mantêm bloqueios em arquivos durante a análise.  Consulte a documentação do programa antivírus para obter detalhes sobre como excluir diretórios específicos da verificação.  
  
 Se o arquivo for bloqueada por um serviço de indexação de pesquisa, você poderá resolver esse problema excluindo os diretórios de saída de compilação de indexação automática.  Consulte a documentação do serviço de indexação para obter mais informações.  Para alterar a conta do serviço de indexação do Windows, use **Opções de Indexação** no **Painel de Controle** do Windows.  Para obter mais informações, consulte [melhorar pesquisas do Windows usando o índice: perguntas frequentes](http://windows.microsoft.com/en-us/windows/improve-windows-searches-using-index-faq#1TC=windows-7).  
  
 Se o executável não puder ser substituído pelo processo de compilação, ele poderá estar bloqueado pelo Explorador de Arquivos.  Se o serviço **Experiência com Aplicativo** estiver desabilitado, o Explorador de Arquivos poderá se ater a um bloqueio de identificador de arquivo executável por um tempo prolongado.  Para resolver esse problema, execute **services.msc** e abra a caixa de diálogo **Propriedades** do serviço **Experiência com Aplicativo**.  Altere o **Tipo de inicialização** de **Desabilitado** para **Manual**.  
  
## Consulte também  
 [Você receberá um "erro PRJ0008" ou uma mensagem de erro "Erro Fatal LNK1168" ao tentar criar uma solução ou um projeto do ActiveX no Visual C\+\+](http://support.microsoft.com/kb/308358)