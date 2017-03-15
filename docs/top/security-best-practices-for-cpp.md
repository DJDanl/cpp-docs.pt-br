---
title: "Pr&#225;ticas recomendadas de seguran&#231;a para C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "securitybestpracticesVC"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "segurança [C++]"
  - "segurança [C++], práticas recomendadas"
  - "Visual C++, segurança"
ms.assetid: 86acaccf-cdb4-4517-bd58-553618e3ec42
caps.latest.revision: 45
caps.handback.revision: 45
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# Pr&#225;ticas recomendadas de seguran&#231;a para C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo contém informações sobre ferramentas e práticas de segurança.  Elas não tornam os aplicativos imunes a ataques, mas diminuem a probabilidade de ataques bem\-sucedidos.  
  
## Recursos de segurança do Visual C\+\+  
 Estes recursos de segurança foram incorporados ao vinculador e ao compilador do Visual C\+\+:  
  
 [\/guard \(habilitar proteção do fluxo de controle\)](../build/reference/guard-enable-control-flow-guard.md)  
 Faz com que o compilador analisar o fluxo de controle para destinos de chamada indireta em tempo de compilação e, em seguida, insira o código para verificar se os destinos em tempo de execução.  
  
 [\/GS \(verificação de segurança do buffer\)](../Topic/-GS%20\(Buffer%20Security%20Check\).md)  
 Instrui o compilador a inserir o código de detecção de saturação em funções que estão em risco de serem exploradas.  Quando uma saturação é detectada, a execução é interrompida.  Por padrão, esta opção está ativada.  
  
 [\/SAFESEH \(a imagem tem manipuladores de exceção seguros\)](../Topic/-SAFESEH%20\(Image%20has%20Safe%20Exception%20Handlers\).md)  
 Instrui o vinculador a incluir na imagem de saída uma tabela que contém o endereço de cada manipulador de exceção.  Em tempo de execução, o sistema operacional usa essa tabela para garantir que apenas os manipuladores de exceção legítimos sejam executados.  Isso ajuda a impedir a execução de manipuladores de exceção introduzidos por um ataque mal\-intencionado em tempo de execução.  Por padrão, essa opção é desativada.  
  
 [\/NXCOMPAT](../Topic/-NXCOMPAT.md), [\/NXCOMPAT \(compatível com Prevenção de Execução de Dados\)](../build/reference/nxcompat-compatible-with-data-execution-prevention.md)  
 Estas opções de compilador e vinculador habilitam a compatibilidade de DEP \(Prevenção de Execução de Dados\).  A DEP protege a CPU contra a execução de páginas sem código.  
  
 [\/analyze \(Análise do código\)](../build/reference/analyze-code-analysis.md)  
 Essa opção do compilador ativa a análise de código que relata problemas potenciais de segurança, como excesso de buffer, memória não inicializada, remoção de referência do ponteiro nulo e vazamentos de memória.  Por padrão, essa opção é desativada.  Para obter mais informações, consulte [Análise de código para visão geral do C\/C\+\+](../Topic/Code%20Analysis%20for%20C-C++%20Overview.md).  
  
 [\/DYNAMICBASE \(usar aleatorização do layout de espaço do endereço\)](../build/reference/dynamicbase-use-address-space-layout-randomization.md)  
 Essa opção do vinculador habilita a criação de uma imagem executável que pode ser carregada em locais diferentes na memória no início da execução.  Essa opção também torna o local da pilha na memória muito menos previsível.  
  
## CRT de segurança aprimorada  
 A biblioteca em tempo de execução C \(CRT\) foi aumentada para incluir versões seguras das funções que oferecem risco de segurança — por exemplo, a função de cópia de cadeia de caracteres de `strcpy` não verificada.  Como as versões anteriores e não seguras dessas funções estão preteridas, elas causam avisos de tempo de compilação.  É recomendável usar as versões seguras dessas funções de CRT em vez de suprimir os avisos de compilação.  Para obter mais informações, consulte [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Biblioteca de SafeInt  
 [Biblioteca de SafeInt](../windows/safeint-library.md) ajuda a evitar estouros de inteiro e outros erros exploráveis que podem ocorrer quando o aplicativo executa operações matemáticas.  O `SafeInt` biblioteca inclui o [Classe SafeInt](../windows/safeint-class.md), o [Classe SafeIntException](../windows/safeintexception-class.md), e várias [Funções \(SafeInt\)](../windows/safeint-functions.md).  
  
 A classe de `SafeInt` protege contra explorações de estouro de inteiro e de divisão por zero.  Você pode usá\-la para tratar comparações entre valores de tipos diferentes.  I fornece duas políticas de tratamento de erro.  A política padrão é que a classe `SafeInt` lance uma exceção da classe `SafeIntException` para relatar por que uma operação matemática não pode ser concluída.  A segunda política é que a classe `SafeInt` interrompa a execução do programa.  Você também pode definir uma política personalizada.  
  
 Cada função de `SafeInt` protege uma operação matemática contra um erro explorável.  Você pode usar dois tipos diferentes de parâmetros sem convertê\-los no mesmo tipo.  Para proteger várias operações matemáticas, use a classe `SafeInt`.  
  
## Iteradores verificados  
 Um iterador verificado impõe limites do contêiner.  Por padrão, quando um iterador verificado está fora dos limites, ele gera uma exceção e finaliza a execução do programa.  Um iterador verificado fornece outros níveis de resposta que dependem dos valores atribuídos às definições do pré\-processador, como **\_SECURE\_SCL\_THROWS** e **\_ITERATOR\_DEBUG\_LEVEL**.  Por exemplo, em **\_ITERATOR\_DEBUG\_LEVEL\=2**, um iterador verificado fornece verificações da correção abrangente no modo de depuração, que são disponibilizadas com o uso de declarações.  Para obter mais informações, consulte [Iteradores Verificados](../standard-library/checked-iterators.md).  
  
## Análise de código para código gerenciado  
 A análise de código para código gerenciado, também conhecida como FxCop, verifica a conformidade dos assemblies de acordo com as diretrizes de design do .NET Framework.  O FxCop analisa o código e os metadados de cada assembly para verificar se há falhas nestas áreas:  
  
-   Design de biblioteca  
  
-   Localização  
  
-   Convenções de nomenclatura  
  
-   Desempenho  
  
-   Segurança  
  
## Verificador de aplicativo do Windows  
 O verificador de aplicativo \(AppVerifier\) pode ajudá\-lo a identificar possíveis problemas de compatibilidade, estabilidade e segurança do aplicativo.  
  
 O AppVerifier monitora como um aplicativo usa o sistema operacional.  Ele inspeciona o sistema de arquivos, o Registro, a memória e as APIs enquanto o aplicativo está em execução, e recomenda correções do código\-fonte dos problemas que ele descobre.  
  
 Também é possível usar o AppVerifier para:  
  
-   Testar possíveis erros de compatibilidade do aplicativo causados por erros comuns de programação.  
  
-   Examinar um aplicativo por problemas relacionados à memória.  
  
-   Identificar possíveis problemas de segurança em um aplicativo.  
  
 O AppVerifier faz parte do Application Compatibility Toolkit, que está disponível a partir de [compatibilidade de aplicativos](http://go.microsoft.com/fwlink/?LinkId=91277) no site do TechNet.  
  
## Recursos de segurança do .NET Framework  
 [NIB: Configuring Security Policy](http://msdn.microsoft.com/pt-br/0f130bcd-1bba-4346-b231-0bcca7dab1a4) descreve diretrizes e ferramentas para ajustar as diretivas de segurança do .NET Framework.  
  
## Contas de usuário do Windows  
 O uso de contas de usuário do Windows que pertencem ao grupo Administradores expõe os desenvolvedores e — por extensão — os clientes a riscos de segurança.  Para obter mais informações, consulte [Executando como um membro do grupo de usuários](../top/running-as-a-member-of-the-users-group.md) e [Como o Controle de Conta de Usuário \(UAC\) afeta o aplicativo](../Topic/How%20User%20Account%20Control%20\(UAC\)%20Affects%20Your%20Application.md).  
  
## Consulte também  
 <xref:System.Security>   
 [Segurança](../Topic/Security%20in%20the%20.NET%20Framework.md)   
 [Como o Controle de Conta de Usuário \(UAC\) afeta o aplicativo](../Topic/How%20User%20Account%20Control%20\(UAC\)%20Affects%20Your%20Application.md)