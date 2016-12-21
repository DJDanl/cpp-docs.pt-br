---
title: "__svm_skinit | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "__svm_skinit"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Instrução SKINIT"
  - "__svm_skinit intrínseco"
ms.assetid: 787ec781-4cf2-40a2-aa20-5192334b131a
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __svm_skinit
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Inicia o carregamento do software comprovadamente seguro, como, por exemplo, um monitor de máquina virtual.  
  
## Sintaxe  
  
```  
void __svm_skinit(  
   int SLB  
);  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`SLB`|O endereço físico de 32 bits de um byte de 64K Secure carregador de bloco \(SLB\).|  
  
## Comentários  
 O `__svm_skinit` função é equivalente a `SKINIT` instrução da máquina.  Essa função é parte de um sistema de segurança que usa o processador e um módulo de plataforma confiável \(TPM\) para verificar e carregar o software confiável, chamado de um núcleo de segurança \(SK\).  Um monitor de máquina virtual é um exemplo de um núcleo de segurança.  O sistema de segurança verifica os componentes do programa carregado durante o processo de inicialização e protege os componentes de violação por interrupções, acesso ao dispositivo ou outro programa, se o computador é um multiprocessador.  
  
 O `SLB` parâmetro especifica o endereço físico de um bloco de 64K de memória chamada a  *Bloco de carregador Secure* \(SLB\).  O SLB contém um programa chamado o carregador de seguro que estabelece o ambiente operacional do computador e, subseqüentemente, carrega o kernel de segurança.  
  
 Esta função oferece suporte a interação do monitor de máquina virtual de um host com um sistema operacional e seus aplicativos de convidado.  Para obter mais informações, procure o documento, "Manual de volumes do programador de arquitetura AMD64 2: programação de sistema," documento número 24593, revisão 3.11, no [corporation AMD](http://go.microsoft.com/fwlink/?LinkId=23746) site.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`__svm_skinit`|x86,[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Específicos do Microsoft final  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)