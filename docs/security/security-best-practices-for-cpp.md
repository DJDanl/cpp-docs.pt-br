---
title: Práticas recomendadas de segurança para C++
ms.date: 05/08/2018
f1_keywords:
- securitybestpracticesVC
helpviewer_keywords:
- Visual C++, security
- security [C++]
- security [C++], best practices
ms.assetid: 86acaccf-cdb4-4517-bd58-553618e3ec42
ms.openlocfilehash: bc449d0bbf222391868dc7586e0245fd6e8cd2ac
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62411260"
---
# <a name="security-best-practices-for-c"></a>Práticas recomendadas de segurança para C++

Este artigo contém informações sobre ferramentas e práticas de segurança. Elas não tornam os aplicativos imunes a ataques, mas diminuem a probabilidade de ataques bem-sucedidos.

## <a name="visual-c-security-features"></a>Recursos de segurança do Visual C++

Estes recursos de segurança foram incorporados ao vinculador e ao compilador do Visual C++:

[/guard (habilitar proteção de fluxo de controle)](../build/reference/guard-enable-control-flow-guard.md)<br/>
Faz com que o compilador analisar o fluxo de controle para destinos de chamada indireta em tempo de compilação e, em seguida, inserir o código para verificar se os destinos em tempo de execução.

[/GS (verificação de segurança do buffer)](../build/reference/gs-buffer-security-check.md)<br/>
Instrui o compilador a inserir o código de detecção de saturação em funções que estão em risco de serem exploradas. Quando uma saturação é detectada, a execução é interrompida. Por padrão, esta opção está ativada.

[/SAFESEH (a imagem tem manipuladores de exceção seguros)](../build/reference/safeseh-image-has-safe-exception-handlers.md)<br/>
Instrui o vinculador a incluir na imagem de saída uma tabela que contém o endereço de cada manipulador de exceção. Em tempo de execução, o sistema operacional usa essa tabela para garantir que apenas os manipuladores de exceção legítimos sejam executados. Isso ajuda a impedir a execução de manipuladores de exceção introduzidos por um ataque mal-intencionado em tempo de execução. Por padrão, essa opção é desativada.

[/NXCOMPAT](../build/reference/nxcompat.md), [/NXCOMPAT (compatível com Data Execution Prevention)](../build/reference/nxcompat-compatible-with-data-execution-prevention.md) essas opções de compilador e vinculador habilitar a compatibilidade de prevenção de execução de dados (DEP). A DEP protege a CPU contra a execução de páginas sem código.

[/analyze (análise de código)](../build/reference/analyze-code-analysis.md)<br/>
Essa opção do compilador ativa a análise de código que relata problemas potenciais de segurança, como excesso de buffer, memória não inicializada, remoção de referência do ponteiro nulo e vazamentos de memória. Por padrão, essa opção é desativada. Para obter mais informações, consulte [análise de código para visão geral do C/C++](/visualstudio/code-quality/code-analysis-for-c-cpp-overview).

[/DYNAMICBASE (usar randomização do layout do espaço de endereço)](../build/reference/dynamicbase-use-address-space-layout-randomization.md)<br/>
Essa opção do vinculador habilita a criação de uma imagem executável que pode ser carregada em locais diferentes na memória no início da execução. Essa opção também torna o local da pilha na memória muito menos previsível.

## <a name="security-enhanced-crt"></a>CRT de segurança aprimorada

A biblioteca em tempo de execução C (CRT) foi aumentada para incluir versões seguras das funções que oferecem risco de segurança — por exemplo, a função de cópia de cadeia de caracteres de `strcpy` não verificada. Como as versões anteriores e não seguras dessas funções estão preteridas, elas causam avisos de tempo de compilação. É recomendável usar as versões seguras dessas funções de CRT em vez de suprimir os avisos de compilação. Para obter mais informações, consulte [Recursos de segurança no CRT](../c-runtime-library/security-features-in-the-crt.md).

## <a name="safeint-library"></a>Biblioteca de SafeInt

[Biblioteca SafeInt](../safeint/safeint-library.md) ajuda a impedir estouros de inteiro e outros erros exploráveis que podem ocorrer quando o aplicativo executa operações matemáticas. O `SafeInt` biblioteca inclui o [classe SafeInt](../safeint/safeint-class.md), o [classe SafeIntException](../safeint/safeintexception-class.md)e várias [funções SafeInt](../safeint/safeint-functions.md).

A classe de `SafeInt` protege contra explorações de estouro de inteiro e de divisão por zero. Você pode usá-la para tratar comparações entre valores de tipos diferentes. Ele fornece duas políticas de tratamento de erro. A política padrão é que a classe `SafeInt` lance uma exceção da classe `SafeIntException` para relatar por que uma operação matemática não pode ser concluída. A segunda política é que a classe `SafeInt` interrompa a execução do programa. Você também pode definir uma política personalizada.

Cada função de `SafeInt` protege uma operação matemática contra um erro explorável. Você pode usar dois tipos diferentes de parâmetros sem convertê-los no mesmo tipo. Para proteger várias operações matemáticas, use a classe `SafeInt`.

## <a name="checked-iterators"></a>Iteradores verificados

Um iterador verificado impõe limites do contêiner. Por padrão, quando um iterador verificado está fora dos limites, ele gera uma exceção e finaliza a execução do programa. Um iterador verificado fornece outros níveis de resposta que dependem de valores que são atribuídos para pré-processador como define  **\_SECURE\_SCL\_lança** e  **\_ITERADOR\_depurar\_nível**. Por exemplo, no  **\_ITERADOR\_DEBUG\_LEVEL = 2**, um iterador verificado fornece verificações da correção abrangente no modo de depuração, que são disponibilizadas por meio declara. Para obter mais informações, consulte [iteradores verificados](../standard-library/checked-iterators.md) e [ \_ITERADOR\_depurar\_nível](../standard-library/iterator-debug-level.md).

## <a name="code-analysis-for-managed-code"></a>Análise de código para código gerenciado

A análise de código para código gerenciado, também conhecida como FxCop, verifica a conformidade dos assemblies de acordo com as diretrizes de design do .NET Framework. O FxCop analisa o código e os metadados de cada assembly para verificar se há falhas nestas áreas:

- Design de biblioteca

- Localização

- Convenções de nomenclatura

- Desempenho

- Segurança

## <a name="windows-application-verifier"></a>Verificador de aplicativo do Windows

O [Application Verifier (AppVerifier)](/windows-hardware/drivers/debugger/application-verifier
) pode ajudá-lo a identificar possíveis problemas de compatibilidade, estabilidade e segurança de aplicativo.

O AppVerifier monitora como um aplicativo usa o sistema operacional. Ele inspeciona o sistema de arquivos, o Registro, a memória e as APIs enquanto o aplicativo está em execução, e recomenda correções do código-fonte dos problemas que ele descobre.

Também é possível usar o AppVerifier para:

- Testar possíveis erros de compatibilidade do aplicativo causados por erros comuns de programação.

- Examinar um aplicativo por problemas relacionados à memória.

- Identificar possíveis problemas de segurança em um aplicativo.

## <a name="windows-user-accounts"></a>Contas de usuário do Windows

O uso de contas de usuário do Windows que pertencem ao grupo Administradores expõe os desenvolvedores e — por extensão — os clientes a riscos de segurança. Para obter mais informações, consulte [em execução como um membro do grupo de usuários](running-as-a-member-of-the-users-group.md) e [como User Account Control (UAC) afeta o seu aplicativo](how-user-account-control-uac-affects-your-application.md).

## <a name="guidance-for-speculative-execution-side-channels"></a>Diretrizes para canais do lado de execução especulativa

Para obter informações sobre como identificar e atenuar vulnerabilidades de hardware de canal de lado de execução especulativa no software de C++, consulte [diretrizes para desenvolvedores de C++ para canais do lado de execução especulativo](developer-guidance-speculative-execution.md).

## <a name="see-also"></a>Consulte também

<xref:System.Security> <br/>
[Segurança](/dotnet/standard/security/index)<br/>
[Como o UAC (Controle de Conta de Usuário) afeta o aplicativo](how-user-account-control-uac-affects-your-application.md)
