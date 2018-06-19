---
title: Executando lb | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLibrarianTool.TargetMachine
- Lib
- VC.Project.VCLibrarianTool.PrintProgress
- VC.Project.VCLibrarianTool.SuppressStartupBanner
dev_langs:
- C++
helpviewer_keywords:
- -MACHINE target platform option
- command files, LIB
- MACHINE target platform option
- colon command files
- VERBOSE library manager option
- /NOLOGO library manager option
- dash option specifier
- /MACHINE target platform option
- forward slash option specifier
- -NOLOGO library manager option
- LIB [C++], running LIB
- -VERBOSE library manager option
- /VERBOSE library manager option
- command files
- NOLOGO library manager option
- slash (/)
- semicolon, command files
- / command files
ms.assetid: d54f5c81-7147-4b2c-a8db-68ce6eb1eabd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c306ba58bfef11f92d7e861272aad2aa605c8fde
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32377568"
---
# <a name="running-lib"></a>Executando LIB
Várias opções de linha de comando podem ser usado para controlar LIB.  
  
## <a name="lib-command-line"></a>Linha de comando LIB  
 Para executar o LIB, digite o comando `lib` seguido as opções e os nomes de arquivo para a tarefa estiver usando LIB para executar. LIB também aceita entrada de linha de comando em arquivos de comando, que são descritos na seção a seguir. Não usa uma variável de ambiente LIB.  
  
> [!NOTE]
>  Se você está acostumado a LINK32.exe e LIB32.exe ferramentas fornecidos com o Microsoft Win32 Software Development Kit para Windows NT, você pode ter sido usando o comando `link32 -lib` ou o comando `lib32` para gerenciar bibliotecas e criando importe bibliotecas. Certifique-se de alterar seus arquivos em lote e makefiles para usar o `lib` comando em vez disso.  
  
## <a name="lib-command-files"></a>Arquivos de comando LIB  
 Você pode passar argumentos de linha de comando para LIB em um arquivo de comando usando a seguinte sintaxe:  
  
```  
LIB @commandfile  
```  
  
 O arquivo `commandfile` é um arquivo de texto. Nenhum espaço ou tabulação é permitida entre o sinal de arroba (@) e o nome do arquivo. Não há nenhuma extensão padrão; Você deve especificar o nome de arquivo completo, incluindo qualquer extensão. Caracteres curinga não pode ser usada. Você pode especificar um caminho absoluto ou relativo com o nome do arquivo.  
  
 No arquivo de comando, os argumentos podem ser separados por espaços ou guias, como eles podem na linha de comando; Eles também podem ser separados por caracteres de nova linha. Use um ponto e vírgula (;) para marcar um comentário. LIB ignora todo o texto de vírgula ao final da linha.  
  
 Você pode especificar todos ou parte da linha de comando em um arquivo de comando, e você pode usar mais de um arquivo de comando em um comando LIB. LIB aceita a entrada do arquivo de comando, como se ele tiver sido especificado nesse local na linha de comando. Arquivos de comando não podem ser aninhados. LIB exibe o conteúdo dos arquivos de comando, a menos que a opção /NOLOGO é usada.  
  
## <a name="using-lib-options"></a>Usando opções de LIB  
 Uma opção consiste em um especificador de opção, que é um traço (-) ou uma barra invertida (/), seguido do nome da opção. Nomes de opção não podem ser abreviados. Algumas opções têm um argumento, especificado após dois-pontos (:). Nenhum tabulações ou espaços são permitidas dentro de uma especificação de opção. Use um ou mais espaços ou guias para separar as especificações de opção na linha de comando. Os nomes de opções e seus argumentos de nome de arquivo ou a palavra-chave não diferenciam maiusculas de minúsculas, mas identificadores usados como argumentos diferenciam maiusculas de minúsculas. LIB processa as opções na ordem especificada na linha de comando e nos arquivos de comando. Se uma opção é repetida com argumentos diferentes, o último para ser processado terá precedência.  
  
 As opções a seguir se aplicam a todos os modos de LIB:  
  
 /ERRORREPORT [NONE &AMP;#124; PROMPT &AMP;#124; FILA &AMP;#124; ENVIAR]  
 Se lib.exe falhar em tempo de execução, você pode usar /ERRORREPORT para enviar à Microsoft informações sobre esses erros internos.  
  
 Para obter mais informações sobre /ERRORREPORT, consulte [/errorReport (relatório de erros do compilador interno)](../../build/reference/errorreport-report-internal-compiler-errors.md).  
  
 /LTCG  
 Faz com que a biblioteca a ser criada usando a geração de código para link-time.  Para obter mais informações, consulte [/LTCG](../../build/reference/ltcg-link-time-code-generation.md).  
  
 /MACHINE  
 Especifica a plataforma de destino para o programa. Normalmente, você não precisa especificar /MACHINE. LIB infere o tipo de computador dos arquivos. obj. No entanto, em algumas circunstâncias, LIB não é possível determinar o tipo de máquina e emite uma mensagem de erro. Se esse erro ocorrer, especifique /MACHINE. No modo /EXTRACT, essa opção é somente para verificação. Use `lib /?` na linha de comando para ver os tipos de máquina disponível.  
  
 /NOLOGO  
 Suprime a exibição do número de mensagem e a versão de direitos autorais do LIB e impede a repetição de arquivos de comando.  
  
 /VERBOSE  
 Exibe detalhes sobre o progresso da sessão, incluindo os nomes dos arquivos. obj que está sendo adicionados. A informação é enviada para uma saída padrão e pode ser redirecionada para um arquivo.  
  
 /WX [: NO]  
 Trate avisos como erros. Consulte [/WX (tratar avisos do vinculador como erros)](../../build/reference/wx-treat-linker-warnings-as-errors.md) para obter mais informações.  
  
 Outras opções se aplicam apenas a modos específicos de LIB. Essas opções são discutidas nas seções que descrevem cada modo.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de LIB](../../build/reference/lib-reference.md)