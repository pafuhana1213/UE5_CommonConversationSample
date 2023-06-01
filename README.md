# UE5_CommonConversationSample
![image](https://user-images.githubusercontent.com/8957600/209765163-e0b76f4d-f1a2-4d98-a814-4d5268a3cf65.png)  
![image](https://user-images.githubusercontent.com/8957600/209765207-9d2b0179-18ee-49fc-95cf-936bd3d8aa43.png)  

UE4.27から追加されているCommon ConversationプラグインをUE5.2で動かしてみたというサンプルプロジェクトです。
上図のようなグラフベースのUIを使って、会話・クエスト・ゲームの進行状況などを管理・制御することができます。

---

This is a sample project of the Common Conversation plugin that has been added since UE4.27 and is now working with **UE5.2**.  
Using the graph-based UI shown above, you can manage and control conversations, quests, game progress, etc.

# Warning
- Common Conversation自体が公式でサポートされていない実験的機能のため、本サンプルも動作保証をしません。何かトラブルが発生した際は独自に解決・拡張・エンジン改造をお願いします。
- 最低限の内容ですので、実際に使用する際はプロジェクトに応じてカスタマイズする必要があります
- Common Conversationの仕様によりBPのみでは実装することができないため、C++プロジェクトになっています。また同じく仕様によりGameFeature機能を活用しています。
- Common Conversationはマルチプレイを想定した機能になっているため、エンジン標準ではシングルプレイゲームでは機能しません。そのため、シングルプレイでも動作するようにC++で専用のBPノードを用意しています。

---

- Since Common Conversation itself is an experimental feature that is not officially supported, this sample is not guaranteed to work. If you encounter any issues, please resolve, extend, or modify the engine on your own.
- Since this is the minimum content, you need to customize it according to your project when you actually use it.
- This is a C++ project because it cannot be implemented using only BP due to the specification of Common Conversation. Also, due to the same specification, the GameFeature feature is utilized.
- Since Common Conversation is designed for multi-player games, it does not work in single-player games by engine standard. Therefore, a dedicated BP node is provided in C++ to allow it to work in single-player games.

# What is Common Conversation?
![image](https://user-images.githubusercontent.com/8957600/209765362-7e9b7974-39b6-4181-a2a8-c216d77a374a.png)
[35 UE5 Features You Probably Don't Know About | Unreal Fest 2022](https://www.youtube.com/watch?v=k2IP5DYQ0-0)

# Description
https://pafuhana1213.hatenablog.com/entry/2022/12/28/165025

# Author
https://twitter.com/pafuhana1213
