---
title: Práticas recomendadas de segurança para C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- securitybestpracticesVC
dev_langs:
- C++
helpviewer_keywords:
- Visual C++, security
- security [C++]
- security [C++], best practices
ms.assetid: 86acaccf-cdb4-4517-bd58-553618e3ec42
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5c7f0860daea5b2e90368c7068c6b13371af3fd8
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="security-best-practices-for-c"></a>Práticas recomendadas de segurança para C++
Este artigo contém informações sobre ferramentas e práticas de segurança. Elas não tornam os aplicativos imunes a ataques, mas diminuem a probabilidade de ataques bem-sucedidos.  
  
## <a name="visual-c-security-features"></a>Recursos de segurança do Visual C++  
 Estes recursos de segurança foram incorporados ao vinculador e ao compilador do Visual C++:  
  
 [/guard (habilitar proteção de fluxo de controle)](../build/reference/guard-enable-control-flow-guard.md)  
 Faz com que o compilador analisar o fluxo de controle para destinos de chamada indireta em tempo de compilação e, em seguida, inserir o código para verificar se os destinos em tempo de execução.  
  
 [/GS (verificação de segurança do buffer)](../build/reference/gs-buffer-security-check.md)  
 Instrui o compilador a inserir o código de detecção de saturação em funções que estão em risco de serem exploradas. Quando uma saturação é detectada, a execução é interrompida. Por padrão, esta opção está ativada.  
  
 [/SAFESEH (a imagem tem manipuladores de exceção seguros)](../build/reference/safeseh-image-has-safe-exception-handlers.md)  
 Instrui o vinculador a incluir na imagem de saída uma tabela que contém o endereço de cada manipulador de exceção. Em tempo de execução, o sistema operacional usa essa tabela para garantir que apenas os manipuladores de exceção legítimos sejam executados. Isso ajuda a impedir a execução de manipuladores de exceção introduzidos por um ataque mal-intencionado em tempo de execução. Por padrão, essa opção é desativada.  
  
 [/NXCOMPAT](../build/reference/nxcompat.md), [/NXCOMPAT (compatível com prevenção de execução de dados)](../build/reference/nxcompat-compatible-with-data-execution-prevention.md)  
 Estas opções de compilador e vinculador habilitam a compatibilidade de DEP (Prevenção de Execução de Dados). A DEP protege a CPU contra a execução de páginas sem código.  
  
 [/analyze (análise de código)](../build/reference/analyze-code-analysis.md)  
 Essa opção do compilador ativa a análise de código que relata problemas potenciais de segurança, como excesso de buffer, memória não inicializada, remoção de referência do ponteiro nulo e vazamentos de memória. Por padrão, essa opção é desativada. Para obter mais informações, consulte [análise de código para visão geral do C/C++](/visualstudio/code-quality/code-analysis-for-c-cpp-overview).  
  
 [/DYNAMICBASE (usar randomização do layout do espaço de endereço)](../build/reference/dynamicbase-use-address-space-layout-randomization.md)  
 Essa opção do vinculador habilita a criação de uma imagem executável que pode ser carregada em locais diferentes na memória no início da execução. Essa opção também torna o local da pilha na memória muito menos previsível.  
  
## <a name="security-enhanced-crt"></a>CRT de segurança aprimorada  
 A biblioteca em tempo de execução C (CRT) foi aumentada para incluir versões seguras das funções que oferecem risco de segurança — por exemplo, a função de cópia de cadeia de caracteres de `strcpy` não verificada. Como as versões anteriores e não seguras dessas funções estão preteridas, elas causam avisos de tempo de compilação. É recomendável usar as versões seguras dessas funções de CRT em vez de suprimir os avisos de compilação. Para obter mais informações, consulte [Recursos de segurança no CRT](../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="safeint-library"></a>Biblioteca de SafeInt  
 [Biblioteca de SafeInt](../windows/safeint-library.md) ajuda a evitar o estouro de inteiro e outros erros exploráveis que podem ocorrer quando o aplicativo executa operações matemáticas. O `SafeInt` biblioteca inclui o [classe SafeInt](../windows/safeint-class.md), o [classe SafeIntException](../windows/safeintexception-class.md)e várias [funções SafeInt](../windows/safeint-functions.md).  
  
 A classe de `SafeInt` protege contra explorações de estouro de inteiro e de divisão por zero. Você pode usá-la para tratar comparações entre valores de tipos diferentes. I fornece duas políticas de tratamento de erro. A política padrão é que a classe `SafeInt` lance uma exceção da classe `SafeIntException` para relatar por que uma operação matemática não pode ser concluída. A segunda política é que a classe `SafeInt` interrompa a execução do programa. Você também pode definir uma política personalizada.  
  
 Cada função de `SafeInt` protege uma operação matemática contra um erro explorável. Você pode usar dois tipos diferentes de parâmetros sem convertê-los no mesmo tipo. Para proteger várias operações matemáticas, use a classe `SafeInt`.  
  
## <a name="checked-iterators"></a>Iteradores verificados  
 Um iterador verificado impõe limites do contêiner. Por padrão, quando um iterador verificado está fora dos limites, ele gera uma exceção e finaliza a execução do programa. Um iterador check fornece outros níveis de resposta que dependem de valores que são atribuídos para pré-processador define como  **\_seguro\_SCL\_lança** e  **\_ITERADOR\_depurar\_nível**. Por exemplo, no  **\_ITERADOR\_depurar\_LEVEL = 2**, um iterador check fornece exatidão abrangente verificações no modo de depuração, que ficam disponível usando declarações. Para obter mais informações, consulte [iteradores](../standard-library/checked-iterators.md) e [ \_ITERADOR\_depurar\_nível](../standard-library/iterator-debug-level.md).  
  
## <a name="code-analysis-for-managed-code"></a>Análise de código para código gerenciado  
 A análise de código para código gerenciado, também conhecida como FxCop, verifica a conformidade dos assemblies de acordo com as diretrizes de design do .NET Framework. O FxCop analisa o código e os metadados de cada assembly para verificar se há falhas nestas áreas:  
  
-   Design de biblioteca  
  
-   Localização  
  
-   Convenções de nomenclatura  
  
-   Desempenho  
  
-   Segurança  
  
## <a name="windows-application-verifier"></a>Verificador de aplicativo do Windows  
 O verificador de aplicativo (AppVerifier) pode ajudá-lo a identificar possíveis problemas de compatibilidade, estabilidade e segurança do aplicativo.  
  
 O AppVerifier monitora como um aplicativo usa o sistema operacional. Ele inspeciona o sistema de arquivos, o Registro, a memória e as APIs enquanto o aplicativo está em execução, e recomenda correções do código-fonte dos problemas que ele descobre.  
  
 Também é possível usar o AppVerifier para:  
  
-   Testar possíveis erros de compatibilidade do aplicativo causados por erros comuns de programação.  
  
-   Examinar um aplicativo por problemas relacionados à memória.  
  s
-   Identificar possíveis problemas de segurança em um aplicativo.  
  
 O AppVerifier faz parte do Application Compatibility Toolkit, que está disponível a partir de [compatibilidade de aplicativos](http://go.microsoft.com/fwlink/p/?linkid=91277) no site do TechNet.  
  

## <a name="windows-user-accounts"></a>Contas de usuário do Windows  
 O uso de contas de usuário do Windows que pertencem ao grupo Administradores expõe os desenvolvedores e — por extensão — os clientes a riscos de segurança. Para obter mais informações, consulte [executando como um membro do grupo de usuários](running-as-a-member-of-the-users-group.md) e [como User Account Control (UAC) afeta seu aplicativo](how-user-account-control-uac-affects-your-application.md).  
  
## <a name="see-also"></a>Consulte também  
 <xref:System.Security>   
 [Segurança](/dotnet/standard/security/index)   
 [Como o UAC (Controle de Conta de Usuário) afeta o aplicativo](how-user-account-control-uac-affects-your-application.md)