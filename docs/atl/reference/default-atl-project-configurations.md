---
title: "Configura&#231;&#245;es padr&#227;o do projeto ATL | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "projetos ATL, configurações padrão"
ms.assetid: 7e272722-41af-4330-b965-a6d74ec16880
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Configura&#231;&#245;es padr&#227;o do projeto ATL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico compara as configurações do projeto de opção ATL no Visual C\+\+ .NET com as configurações de projeto padrão no Visual C\+\+ 6,0.  
  
## Configurações padrão do Visual C\+\+ .NET  
 Em o Visual C\+\+ .NET, o assistente de projeto de ATL cria duas configurações do projeto por padrão.  
  
### Configurações do Visual C\+\+ .NET  
  
|Configuração|Conjunto de caracteres|uso de ATL|  
|------------------|----------------------------|----------------|  
|Versão|MBCS|DLL|  
|Depurar|MBCS|DLL|  
  
 **Conjunto de caracteres**, **Uso da ATL** e pode ser alterado na caixa de diálogo **Configurações do projeto** na guia **Geral**.  Você também pode adicionar suas próprias configurações usando Configuration Manager.  Para obter detalhes, consulte [Configurações de compilação](../Topic/Understanding%20Build%20Configurations.md).  
  
## Configurações padrão de versão 6,0  
 Em a versão 6,0 Visual C\+\+, o ATL COM AppWizard \(chamado agora o assistente de projeto de ATL\) criou seis configurações do projeto por padrão.  As configurações eram variações na versão, a depuração, em Unicode, e uso das configurações de CRT e de ATL.  Todas essas configurações podem ser duplicadas no Visual C\+\+ .NET usando o Configuration Manager, se desejadas isso.  
  
### Configurações de versão 6,0  
  
|Configuração|Conjunto de caracteres|uso de ATL|  
|------------------|----------------------------|----------------|  
|Depurar|MBCS|Estático|  
|depuração Unicode|UNICODE|Estático|  
|Dependência do minuto de versão|MBCS|Estático|  
|Unicode versão mínima de dependência|UNICODE|Estático|  
|Tamanho mínimo de versão|MBCS|DLL|  
|Unicode tamanho mínimo de versão|UNICODE|DLL|  
  
## Consulte também  
 [Programando com código de tempo de execução ATL e C](../../atl/programming-with-atl-and-c-run-time-code.md)   
 [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md)   
 [Configuration Manager Dialog Box](http://msdn.microsoft.com/pt-br/fa182dca-282e-4ae5-bf37-e155344ca18b)   
 [Compilando aplicativos no Visual Studio](../Topic/Compiling%20and%20Building%20in%20Visual%20Studio.md)